function init_wifi()
	wifi.setmode(wifi.STATION)
	print('set mode=STATION (mode='..wifi.getmode()..')')
	print('MAC: ',wifi.sta.getmac())
	print('chip: ',node.chipid())
	print('heap: ',node.heap())
	wifi.sta.config("32C3-open-legacy", "")
end

function check_wifi()
	if wifi.sta.getip() == nil then
		init_wifi()
		tmr.alarm(0, 5000, tmr.ALARM_SINGLE, function() check_wifi() end)
	else
		print("got ip" .. wifi.sta.getip())
		--tmr.alarm(0, 5000, tmr.ALARM_SINGLE, function() dofile("mqtt.lua") end)
		r()
		dofile("superserver.lua")
	end
end

check_wifi()


function r()
  ledmate.run()
  tmr.alarm(0, 10, tmr.ALARM_SINGLE, function() r() end)
end

ledmate.run()
r()
