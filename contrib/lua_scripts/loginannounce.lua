local TEAM_ALLIANCE=0
local TEAM_HORDE=1
--CLASS					职业	
local CLASS_WARRIOR 		= 1		--战士
local CLASS_PALADIN			= 2		--圣骑士
local CLASS_HUNTER			= 3		--猎人
local CLASS_ROGUE			= 4		--盗贼
local CLASS_PRIEST			= 5		--牧师
local CLASS_DEATH_KNIGHT	= 6		--死亡骑士
local CLASS_SHAMAN			= 7		--萨满
local CLASS_MAGE			= 8		--法师
local CLASS_WARLOCK			= 9		--术士
local CLASS_DRUID			= 11	--德鲁伊

local ClassName={--职业表
	[CLASS_WARRIOR]	="战士",
	[CLASS_PALADIN]	="圣骑士",
	[CLASS_HUNTER]	="猎人",
	[CLASS_ROGUE]	="盗贼",
	[CLASS_PRIEST]	="牧师",
	[CLASS_DEATH_KNIGHT]="死亡骑士",
	[CLASS_SHAMAN]	="萨满",
	[CLASS_MAGE]	="法师",
	[CLASS_WARLOCK]	="术士",
	[CLASS_DRUID]	="德鲁伊",
}

local function GetPlayerInfo(player)--得到玩家信息
	local Pclass	= ClassName[player:GetClass()] or "? ? ?" --得到职业
	local Pname		= player:GetName()
	local Pteam		= ""
	local team=player:GetTeam()
	if(team==TEAM_ALLIANCE)then
		Pteam		="|cFF0070d0联盟|r"
	elseif(team==TEAM_HORDE)then 
		Pteam		="|cFFF000A0部落|r"
	end
	return string.format("%s%s玩家[|cFF00FF00|Hplayer:%s|h%s|h|r]",Pteam,Pclass,Pname,Pname)
end

local function PlayerFirstLogin(event, player)--玩家首次登录
	SendWorldMessage("|cFFFF0000[系统公告]欢迎|r"..GetPlayerInfo(player).." |cFFFF0000来到怀旧魔兽！|r")
	print("Player is Created. GUID:"..player:GetGUIDLow())
end

local function PlayerLogin(event, player)--玩家登录
	SendWorldMessage("|cFFFF0000[系统公告]|r欢迎"..GetPlayerInfo(player).." 上线了！")
	print("Player is Login. GUID:"..player:GetGUIDLow())
end

local function PlayerLogout(event, player)--玩家登出
	SendWorldMessage("|cFFFF0000[系统公告]|r"..GetPlayerInfo(player).." 下线了！")
	print("Player is Logout. GUID:"..player:GetGUIDLow())
end

--PLAYER_EVENT_ON_FIRST_LOGIN             =     30       -- (event, player)
	RegisterPlayerEvent(30, PlayerFirstLogin)--首次登录
--PLAYER_EVENT_ON_LOGIN                   =     3        -- (event, player)
	RegisterPlayerEvent(3, PlayerLogin)--登录
--PLAYER_EVENT_ON_LOGOUT                  =     4        -- (event, player)
	RegisterPlayerEvent(4, PlayerLogout)--登出