/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "LoginDatabase.h"

void LoginDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_LOGINDATABASE_STATEMENTS);

    PrepareStatement(LOGIN_SEL_REALMLIST, "SELECT id, project_shortname, address, port, icon, flag, timezone, allowedSecurityLevel, population, gamebuild FROM realmlist WHERE flag <> 3 ORDER BY name", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_REALMNAME_BY_ID, "SELECT project_shortname FROM realmlist WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_DEL_EXPIRED_IP_BANS, "DELETE FROM ip_banned WHERE unbandate<>bandate AND unbandate<=UNIX_TIMESTAMP()", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_EXPIRED_ACCOUNT_BANS, "UPDATE account_banned SET active = 0 WHERE active = 1 AND unbandate<>bandate AND unbandate<=UNIX_TIMESTAMP()", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_IP_BANNED, "SELECT * FROM ip_banned WHERE ip = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_IP_AUTO_BANNED, "INSERT INTO ip_banned (ip, bandate, unbandate, bannedby, banreason) VALUES (?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, 'Trinity realmd', 'Failed login autoban')", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_IP_BANNED_ALL, "SELECT ip, bandate, unbandate, bannedby, banreason FROM ip_banned WHERE (bandate = unbandate OR unbandate > UNIX_TIMESTAMP()) ORDER BY unbandate", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_IP_BANNED_BY_IP, "SELECT ip, bandate, unbandate, bannedby, banreason FROM ip_banned WHERE (bandate = unbandate OR unbandate > UNIX_TIMESTAMP()) AND ip LIKE CONCAT('%%', ?, '%%') ORDER BY unbandate", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BANNED, "SELECT bandate, unbandate FROM account_banned WHERE id = ? AND active = 1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BANNED_ALL, "SELECT account.id, username FROM account, account_banned WHERE account.id = account_banned.id AND active = 1 GROUP BY account.id", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BANNED_BY_USERNAME, "SELECT account.id, username FROM account, account_banned WHERE account.id = account_banned.id AND active = 1 AND username LIKE CONCAT('%%', ?, '%%') GROUP BY account.id", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_ACCOUNT_AUTO_BANNED, "INSERT INTO account_banned (id, realm, bandate, unbandate, bannedBy, banreason, active) VALUES (?, ?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, 'Trinity realmd', 'Failed login autoban', 1)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_ACCOUNT_BANNED, "DELETE FROM account_banned WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_SESSIONKEY, "SELECT a.sessionkey, a.id, aa.gmlevel  FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_VS, "UPDATE account SET v = ?, s = ? WHERE username = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_LOGONPROOF, "UPDATE account SET sessionkey = ?, last_ip = ?, last_login = NOW(), locale = ?, failed_logins = 0, os = ? WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_LOGONCHALLENGE, "SELECT a.sha_pass_hash, a.id, a.locked, a.last_ip, aa.gmlevel, a.v, a.s FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_FAILEDLOGINS, "UPDATE account SET failed_logins = failed_logins + 1 WHERE username = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_FAILEDLOGINS, "SELECT id, failed_logins FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_ID_BY_NAME, "SELECT id FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_LIST_BY_NAME, "SELECT id, username FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_INFO_BY_NAME, "SELECT id, sessionkey, last_ip, locked, expansion, mutetime, locale, recruiter, os, flags, online_mute_timer, active_mute_id FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_LIST_BY_EMAIL, "SELECT id, username FROM account WHERE email = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_LIST_BY_HWID, "SELECT id, username FROM account WHERE project_hwid = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_NUM_CHARS_ON_REALM, "SELECT numchars FROM realmcharacters WHERE realmid = ? AND acctid= ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BY_IP, "SELECT id, username FROM account WHERE last_ip = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BY_ID, "SELECT 1 FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_IP_BANNED, "INSERT INTO ip_banned (ip, bandate, unbandate, bannedby, banreason) VALUES (?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_IP_NOT_BANNED, "DELETE FROM ip_banned WHERE ip = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_ACCOUNT_BANNED, "INSERT INTO account_banned (id, realm, bandate, unbandate, bannedBy, banreason, active) VALUES (?, ?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, ?, ?, 1)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_NOT_BANNED, "UPDATE account_banned SET active = 0 WHERE id = ? AND active != 0", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_REALM_CHARACTERS_BY_REALM, "DELETE FROM realmcharacters WHERE acctid = ? AND realmid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_REALM_CHARACTERS, "DELETE FROM realmcharacters WHERE acctid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_REALM_CHARACTERS, "INSERT INTO realmcharacters (numchars, acctid, realmid) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_SUM_REALM_CHARACTERS, "SELECT SUM(numchars) FROM realmcharacters WHERE acctid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_ACCOUNT, "INSERT INTO account(username, sha_pass_hash, email, joindate) VALUES(?, ?, ?, NOW())", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_REALM_CHARACTERS_INIT, "INSERT INTO realmcharacters (realmid, acctid, numchars) SELECT DISTINCT realmlist.id, account.id, 0 FROM realmlist,account LEFT JOIN realmcharacters ON acctid=account.id WHERE acctid IS NULL", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_EXPANSION, "UPDATE account SET expansion = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_LOCK, "UPDATE account SET locked = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_LOG, "INSERT INTO logs (time, realm, type, string) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_USERNAME, "UPDATE account SET v = 0, s = 0, username = ?, sha_pass_hash = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_PASSWORD, "UPDATE account SET v = 0, s = 0, sha_pass_hash = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_EMAIL, "UPDATE account SET email = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_LAST_IP, "UPDATE account SET last_ip = ? WHERE username = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_ONLINE, "UPDATE account SET online = 1 WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_UPTIME_PLAYERS, "UPDATE uptime SET uptime = ?, maxplayers = ? WHERE realmid = ? AND starttime = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_OLD_LOGS, "DELETE FROM logs WHERE (time + ?) < ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_ACCOUNT_ACCESS, "DELETE FROM account_access WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_ACCOUNT_ACCESS_BY_REALM, "DELETE FROM account_access WHERE id = ? AND (RealmID = ? OR RealmID = -1)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_ACCOUNT_ACCESS, "INSERT INTO account_access (id,gmlevel,RealmID) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_GET_ACCOUNT_ID_BY_USERNAME, "SELECT id FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_ACCOUNT_ACCESS_GMLEVEL, "SELECT gmlevel FROM account_access WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_GMLEVEL_BY_REALMID, "SELECT gmlevel FROM account_access WHERE id = ? AND (RealmID = ? OR RealmID = -1)", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_USERNAME_BY_ID, "SELECT username FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_CHECK_PASSWORD, "SELECT 1 FROM account WHERE id = ? AND sha_pass_hash = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_CHECK_PASSWORD_BY_NAME, "SELECT 1 FROM account WHERE username = ? AND sha_pass_hash = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_PINFO, "SELECT a.username, aa.gmlevel, a.email, a.last_ip, DATE_FORMAT(a.last_login, '%Y-%m-%d %T'), a.mutetime, a.failed_logins, a.locked, a.OS, a.project_hwid, ba.email, a.online_mute_timer, a.active_mute_id FROM account a LEFT JOIN account_access aa ON (a.id = aa.id AND (aa.RealmID = ? OR aa.RealmID = -1)) LEFT JOIN battlenet_accounts ba ON a.project_member_id = ba.project_member_id WHERE a.id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_PINFO_BANS, "SELECT unbandate, bandate = unbandate, bannedby, banreason FROM account_banned WHERE id = ? AND active ORDER BY bandate ASC LIMIT 1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_GM_ACCOUNTS, "SELECT a.username, aa.gmlevel FROM account a, account_access aa WHERE a.id=aa.id AND aa.gmlevel >= ? AND (aa.realmid = -1 OR aa.realmid = ?)", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_INFO, "SELECT a.username, a.last_ip, aa.gmlevel, a.expansion FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_ACCESS_GMLEVEL_TEST, "SELECT 1 FROM account_access WHERE id = ? AND gmlevel > ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_ACCESS, "SELECT a.id, aa.gmlevel, aa.RealmID FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_RECRUITER, "SELECT 1 FROM account WHERE recruiter = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BANS, "SELECT 1 FROM account_banned WHERE id = ? AND active = 1 UNION SELECT 1 FROM ip_banned WHERE ip = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_WHOIS, "SELECT username, email, last_ip FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_REALMLIST_SECURITY_LEVEL, "SELECT allowedSecurityLevel from realmlist WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_DEL_ACCOUNT, "DELETE FROM account WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_AUTOBROADCAST, "SELECT id, weight, text FROM autobroadcast WHERE realmid = ? OR realmid = -1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_EMAIL_BY_ID, "SELECT email FROM account WHERE id = ?", CONNECTION_SYNCH);

    PrepareStatement(LOGIN_SEL_ACCOUNT_ACCESS_BY_ID, "SELECT gmlevel, RealmID FROM account_access WHERE id = ? and (RealmID = ? OR RealmID = -1) ORDER BY gmlevel desc", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_DIFF_STAT, "REPLACE INTO realm_diff_stats (realm_id, diff, min, max, unixtime) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);

    //PrepareStatement(LOGIN_SEL_ACCOUNT_INFO_BY_BNET, "SELECT id, sessionkey, last_ip, locked, expansion, mutetime, locale, recruiter, os FROM account WHERE battlenet_account = ? AND battlenet_index = ?", CONNECTION_SYNCH);

#define BnetAccountInfo "ba.id, UPPER(ba.email), ba.last_ip, ba.failed_logins, bab.unbandate > UNIX_TIMESTAMP() OR bab.unbandate = bab.bandate, bab.unbandate = bab.bandate"
#define BnetGameAccountInfo "a.id, a.username, ab.unbandate > UNIX_TIMESTAMP() OR ab.unbandate = ab.bandate, ab.unbandate = ab.bandate, aa.gmlevel"

    PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_INFO, "SELECT " BnetAccountInfo ", ba.sha_pass_hash, ba.v, ba.s, " BnetGameAccountInfo
        " FROM battlenet_accounts ba LEFT JOIN battlenet_account_bans bab ON ba.id = bab.id LEFT JOIN account a ON ba.project_member_id = a.project_member_id"
        " LEFT JOIN account_banned ab ON a.id = ab.id AND ab.active = 1 LEFT JOIN account_access aa ON a.id = aa.id AND aa.RealmID = -1 WHERE ba.email = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_VS_FIELDS, "UPDATE battlenet_accounts SET v = ?, s = ? WHERE email = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_SESSION_KEY, "UPDATE battlenet_accounts SET sessionKey = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_RECONNECT_INFO, "SELECT " BnetAccountInfo ", ba.sessionKey, " BnetGameAccountInfo
        " FROM battlenet_accounts ba LEFT JOIN battlenet_account_bans bab ON ba.id = bab.id LEFT JOIN account a ON ba.project_member_id = a.project_member_id"
        " LEFT JOIN account_banned ab ON a.id = ab.id AND ab.active = 1 LEFT JOIN account_access aa ON a.id = aa.id AND aa.RealmID = -1 WHERE ba.email = ? AND a.username = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_FAILED_LOGINS, "UPDATE battlenet_accounts SET failed_logins = failed_logins + 1 WHERE email = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_LAST_LOGIN_INFO, "UPDATE battlenet_accounts SET last_ip = ?, failed_logins = 0 WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS, "SELECT rc.numchars, r.id, r.gamebuild FROM realmcharacters rc INNER JOIN realmlist r ON rc.realmid = r.id WHERE rc.acctid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BNET_ACCOUNT, "INSERT INTO battlenet_accounts (`email`,`sha_pass_hash`) VALUES (?, ?)", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_EMAIL_BY_ID, "SELECT email FROM battlenet_accounts WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_EMAIL, "SELECT id FROM battlenet_accounts WHERE email = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_BNET_PASSWORD, "UPDATE battlenet_accounts SET v = '', s = '', sha_pass_hash = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_CHECK_PASSWORD, "SELECT 1 FROM battlenet_accounts WHERE id = ? AND sha_pass_hash = ?", CONNECTION_SYNCH);
    //PrepareStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK, "UPDATE battlenet_accounts SET locked = ? WHERE id = ?", CONNECTION_ASYNC);
    //PrepareStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK_CONTRY, "UPDATE battlenet_accounts SET lock_country = ? WHERE id = ?", CONNECTION_ASYNC);
    //PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_GAME_ACCOUNT, "SELECT battlenet_account FROM account WHERE id = ?", CONNECTION_SYNCH);
    //PrepareStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LINK, "UPDATE account SET battlenet_account = ?, battlenet_index = ? WHERE id = ?", CONNECTION_ASYNC);
    //PrepareStatement(LOGIN_SEL_BNET_MAX_ACCOUNT_INDEX, "SELECT MAX(battlenet_index) FROM account WHERE battlenet_account = ?", CONNECTION_SYNCH);

    // boost
    PrepareStatement(LOGIN_SEL_ACCOUNT_BOOST, "SELECT counter FROM account_boost WHERE id = ? AND realmid = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_ACCOUNT_BOOST, "REPLACE INTO account_boost (id, realmid, counter) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_ACCOUNT_BOOST, "DELETE FROM account_boost WHERE id = ? AND realmid = ?", CONNECTION_ASYNC);

    // BattlePay
    PrepareStatement(LOGIN_SEL_BATTLEPAY_COINS, "SELECT dp FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_BATTLEPAY_INCREMENT_COINS, "UPDATE account SET dp = dp - ? WHERE id = ?;", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_BATTLEPAY_DECREMENT_COINS, "UPDATE account SET dp = dp - ? WHERE id = ?;", CONNECTION_SYNCH);

    // Custom Reward
    PrepareStatement(LOGIN_UPD_BATTLEPAY_VP_COINS, "UPDATE account SET vp = vp + ? WHERE id = ?;", CONNECTION_SYNCH);
    
    // WoW-Token
    PrepareStatement(LOGIN_INS_WOW_TOKEN, "INSERT INTO wow_token (accountId, characterGuid, realm, coins) VALUES (?, ?, ?, ?)", CONNECTION_SYNCH);

    // project
    PrepareStatement(LOGIN_SEL_project_MEMBER_PREMIUM, "SELECT unsetdate FROM project_member_premiums WHERE (member_id = ? OR member_id = 0) AND active = 1 ORDER BY unsetdate DESC", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_VERIFIED, "SELECT 1 FROM account WHERE project_member_id = ? AND project_verified LIMIT 1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_project_MEMBER_SETTINGS, "SELECT setting, value FROM project_member_settings WHERE member_id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_REP_project_MEMBER_SETTING, "REPLACE INTO project_member_settings (member_id, setting, value) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_project_MEMBER_SETTING, "DELETE FROM project_member_settings WHERE member_id = ? AND setting = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_project_MEMBER_TODAYS_DAILY_REWARDS, "SELECT source_id FROM project_member_rewards WHERE member_id = ? AND source_type = ? AND reward_day = ? AND realmid = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_project_MEMBER_REWARD, "INSERT INTO project_member_rewards (member_id, character_guid, account_id, realmid, source_type, source_id, reward_amount, reward_date, reward_day) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);

    PrepareStatement(LOGIN_INS_ARENA_GAMES, "INSERT INTO arena_games (`gameid`, `teamid`, `guid`, `changeType`, `ratingChange`, `teamRating`, `damageDone`, `deaths`, `healingDone`, `damageTaken`, `healingTaken`, `killingBlows`, `damageAbsorbed`, `timeControlled`, `aurasDispelled`, `aurasStolen`, `highLatencyTimes`, `spellsPrecast`, `mapId`, `start`, `end`, `class`, `season`, `type`, `realmid`, `matchMakerRating`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
}
