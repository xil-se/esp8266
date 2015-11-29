function init_wifi()
	wifi.setmode(wifi.STATION)
	print('set mode=STATION (mode='..wifi.getmode()..')')
	print('MAC: ',wifi.sta.getmac())
	print('chip: ',node.chipid())
	print('heap: ',node.heap())
	-- wifi config start
	wifi.sta.config(wifi_ap, wifi_key)
	-- wifi config end
end

function check_wifi()
  if wifi.sta.getip() == nil then init_wifi() else print(wifi.sta.getip()) end
  tmr.alarm(0, 5000, tmr.ALARM_SINGLE, function() check_wifi() end)
end

dofile("config.lua")
check_wifi()
--dofile("poll.lua")
dofile("server_udp.lua")
