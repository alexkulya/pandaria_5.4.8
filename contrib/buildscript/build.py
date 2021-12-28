#!/usr/bin/python

import subprocess
import os
import sys
import json
import datetime
import getopt
import signal

BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE = range(8)

# http://blog.mathieu-leplatre.info/colored-output-in-console-with-python.html
# following from Python cookbook, #475186
def has_colours(stream):
    if not hasattr(stream, "isatty"):
        return False
    if not stream.isatty():
        return False # auto color only on TTYs
    try:
        import curses
        curses.setupterm()
        return curses.tigetnum("colors") > 2
    except:
    # guess false in case of error
        return False

has_colours = has_colours(sys.stdout)

def colorize(text, colour):
    if has_colours:
        return "\x1b[1;%dm" % (30+colour) + text + "\x1b[0m"
    else:
        return text

def showhelp():
    print("Usage: {0}".format(sys.argv[0]))
    print("Options:")
    print("  -j N            Parallel build, jobs count")
    print("  --clean         Run \"make clean\" before build")
    print("  -c config       Path to config file")
    print("  -b bracnh       Branch to update")
    print("  -C              Remove local changes before build")
    print("  --authserver    Build also authserver target")
    print("  --no-sql        Don't execute sql files")
    print("  --no-build      Don't run build")
    print("  -h, --help      Shows this message")
    print("  -s              Build with sanitizer")
    sys.exit()

def runcmd(cmd):
    p = subprocess.Popen(cmd.split())
    p.wait()
    if p.returncode != 0:
        exit(-1)

def ensure_dir(path):
    if not os.path.exists(path):
        os.makedirs(path)

# read command line arguments, if any
threads = 8
cfgpath = "./config.json"
clean   =  False
cfg     = { }
auth    = 0
branch  = ''
hgopt   = ''
sanitize= 0
exe_sql = True
nobuild = False

opts, args = getopt.getopt(sys.argv[1:], "j:c:b:Chs",["clean", "authserver", "help", "no-sql", "no-build"])
for opt, arg in opts:
    if opt == "-j":
        threads = int(arg)
    elif opt == "-c":
        cfgpath = arg
    elif opt == "--clean":
        clean = True
    elif opt == "--authserver":
        auth = 1
    elif opt == "-b":
        branch = arg
    elif opt == "-C":
        hgopt += "-C "
    elif opt == "--no-sql":
        exe_sql = False
    elif opt == "--no-build":
        nobuild = True
    elif opt == "-s":
        sanitize = 1
    elif opt == "-h" or opt == "--help":
        showhelp()

# read config
if os.path.isfile(cfgpath):
    f = open(cfgpath)
    cfg = json.load(f);
else:
    print("config not found")
    sys.exit(-1)

install_dir     = cfg.get('install_dir')
source_dir      = cfg.get('source_dir')
build_dir       = cfg.get('build_dir')
executable_name = cfg.get('executable_name')
enable_sql      = cfg.get('enable_sql', True)
updater_path    = cfg.get('updater_path', '')
updater_config  = cfg.get('updater_config')
if branch == '':
    branch      = cfg.get('branch', 'default')

# setup commands
make  = "make -j " + str(threads)
cmake = "cmake " + source_dir + " -DCMAKE_INSTALL_PREFIX=" + install_dir + " -DAUTH_SERVER=" + str(auth) + " -DWITH_SANITIZER=" + str(sanitize)
sqlupdate = "{0} -c {1}".format(updater_path,updater_config);
install_dir += "/bin/"
cmds = ["hg pull", "hg up " + hgopt + branch]

lockfile = os.getcwd() + '/build.lock'

# check lock
if (os.path.isfile(lockfile)):
    print(colorize('Build already in progress by another instance', RED))
    sys.exit(-1)

def exit(code = 0):
    os.remove(lockfile)
    sys.exit(code)

def interrupt_handler(signal, frame):
    exit(-1)

# before file creation
signal.signal(signal.SIGINT, interrupt_handler)

# acquire lock
open(lockfile, 'w').close()

os.chdir(source_dir)

# execute all commands
for cmd in cmds:
    runcmd(cmd)

if nobuild:
    if not enable_sql:
        print(colorize("--no-build used when SQL update disabled", RED))
        exit(-1)
    runcmd(sqlupdate)
    exit()  # okay...

# go to build directory, becasue cmake has no such option
ensure_dir(build_dir)
os.chdir(build_dir)
runcmd(cmake)

if clean:
   runcmd("make clean")

starttime = datetime.datetime.now()
runcmd(make)
diff = datetime.datetime.now() - starttime
runcmd("make install")

# go to install directory
os.chdir(install_dir)

today = datetime.date.today()
template = "{0}{1:_%m_%d}".format(install_dir + executable_name, today)
old = template
if os.path.exists(old):
    i = 2
    old = template + "_" + str(i)
    while os.path.exists(old):
        i = i + 1
        old = template + "_" + str(i)

if enable_sql and exe_sql:
    runcmd(sqlupdate)

original = install_dir + executable_name;
target   = install_dir + "worldserver"

# error in config
if not os.path.exists(target):
    print(colorize("Ooops file {0} not found".format(target), RED))
    exit(-1)

# just in case if the original file is not found, may be error in config
if os.path.exists(original):
    os.rename(original, old)
    print(colorize("\n{0} -> {1}".format(original, old), CYAN))
else:
    print(colorize("Original file {0} not found!".format(original), RED))

os.rename(target, original)
print(colorize("{0} -> {1}".format(target, original), CYAN))
print(colorize("Built in {0}".format(diff), GREEN))
exit()
