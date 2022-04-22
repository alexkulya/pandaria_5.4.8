local TEAM_ALLIANCE=0
local TEAM_HORDE=1
--CLASS				
local CLASS_WARRIOR 		= 1		
local CLASS_PALADIN			= 2		
local CLASS_HUNTER			= 3		
local CLASS_ROGUE			= 4		
local CLASS_PRIEST			= 5		
local CLASS_DEATH_KNIGHT	= 6		
local CLASS_SHAMAN			= 7		
local CLASS_MAGE			= 8		
local CLASS_WARLOCK			= 9		
local CLASS_DRUID			= 11	

local ClassName={
	[CLASS_WARRIOR]	="WARRIOR",
	[CLASS_PALADIN]	="PALADIN",
	[CLASS_HUNTER]	="HUNTER",
	[CLASS_ROGUE]	="ROGUE",
	[CLASS_PRIEST]	="PRIEST",
	[CLASS_DEATH_KNIGHT]="DEATH_KNIGHT",
	[CLASS_SHAMAN]	="SHAMAN",
	[CLASS_MAGE]	="MAGE",
	[CLASS_WARLOCK]	="WARLOCK",
	[CLASS_DRUID]	="DRUID",
}

local function GetPlayerInfo(player)
	local Pclass	= ClassName[player:GetClass()] or "? ? ?" 
	local Pname		= player:GetName()
	local Pteam		= ""
	local team=player:GetTeam()
	if(team==TEAM_ALLIANCE)then
		Pteam		="|cFF0070d0 Alliance|r"
	elseif(team==TEAM_HORDE)then 
		Pteam		="|cFFF000A0 Horde|r"
	end
	return string.format("%s%sPlayer[|cFF00FF00|Hplayer:%s|h%s|h|r]",Pteam,Pclass,Pname,Pname)
end

local function PlayerFirstLogin(event, player)
	SendWorldMessage("|cFFFF0000[announce] Welcome|r"..GetPlayerInfo(player).." |cFFFF0000 join the server!|r")
	print("Player is Created. GUID:"..player:GetGUIDLow())
end

local function PlayerLogin(event, player)
	SendWorldMessage("|cFFFF0000[announce]|r Welcome"..GetPlayerInfo(player).." online!")
	print("Player is Login. GUID:"..player:GetGUIDLow())
end

local function PlayerLogout(event, player)
	SendWorldMessage("|cFFFF0000[announce]|r"..GetPlayerInfo(player).." offline!")
	print("Player is Logout. GUID:"..player:GetGUIDLow())
end

--PLAYER_EVENT_ON_FIRST_LOGIN             =     30       -- (event, player)
	RegisterPlayerEvent(30, PlayerFirstLogin)
--PLAYER_EVENT_ON_LOGIN                   =     3        -- (event, player)
	RegisterPlayerEvent(3, PlayerLogin)
--PLAYER_EVENT_ON_LOGOUT                  =     4        -- (event, player)
	RegisterPlayerEvent(4, PlayerLogout)