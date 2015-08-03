function init_wifi()
	wifi.setmode(wifi.STATION)
	print('set mode=STATION (mode='..wifi.getmode()..')')
	print('MAC: ',wifi.sta.getmac())
	print('chip: ',node.chipid())
	print('heap: ',node.heap())
	-- wifi config start
	wifi.sta.config("cyborg","talibaner")
	-- wifi config end
end

function check_wifi()
  if wifi.sta.getip() == nil then init_wifi() end
  tmr.alarm(0, 5000, tmr.ALARM_SINGLE, function() check_wifi() end)
end

check_wifi()
dofile("api-key.lua")
dofile("poll.lua")
