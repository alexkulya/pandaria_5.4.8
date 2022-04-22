print(">> WORLD CHAT #w")
local ChatPrefix = "#w";
local WorldChannelName = "WORLD";
local CooldownTimer = 5; -- Cooldown in seconds. Set to 0 for no CD obviously.
 
local Class = { -- Class colors :) Prettier and easier than the elseif crap :) THESE ARE HEX COLORS!
    [1] = "C79C6E", -- Warrior
    [2] = "F58CBA", -- Paladin
    [3] = "ABD473", -- Hunter
    [4] = "FFF569", -- Rogue
    [5] = "FFFFFF", -- Priest
    [6] = "C41F3B", -- Death Knight
    [7] = "0070DE", -- Shaman
    [8] = "69CCF0", -- Mage
    [9] = "9482C9", -- Warlock
    [11] = "FF7d0A" -- Druid
};
 
local Rank = {
    [0] = "7DFF00", -- Player
    [1] = "E700B1", -- Moderator
    [2] = "E7A200", -- Game Master
    [3] = "E7A200", -- Admin
    [4] = "E7A200" -- Console
};
 
-- Do not edit below unless you know what you're doing :)
if (ChatPrefix:sub(-1) ~= " ") then
    ChatPrefix = ChatPrefix.." ";
end
 
local RCD = {};
function ChatSystem(event, player, msg, _, lang)
    if (RCD[player:GetGUIDLow()] == nil) then
        RCD[player:GetGUIDLow()] = 0;
    end

    if (msg:sub(1, ChatPrefix:len()) == ChatPrefix) then
        local r = RCD[player:GetGUIDLow()] - os.clock();
        if (0 < r) then
            local s = string.format("|cFFFF0000You must wait %i second(s) before sending another chat message!|r", math.floor(r));
            player:SendAreaTriggerMessage(s);
        else
            RCD[player:GetGUIDLow()] = os.clock() + CooldownTimer;
            local t = table.concat({"|cff7DFF00[", WorldChannelName, "] [|r|cff", Rank[player:GetGMRank()] or Rank[0], "|Hplayer:", player:GetName(), "|h", player:GetName(), "|h|r|cff7DFF00]: |r|cff", Class[player:GetClass()], msg:sub(ChatPrefix:len()+1), "|r"});
            SendWorldMessage(t);
        end
        return false;
    end
end
 
RegisterPlayerEvent(18, ChatSystem);
RegisterPlayerEvent(4, function(_, player) RCD[player:GetGUIDLow()] = 0; end);