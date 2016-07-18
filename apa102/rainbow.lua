clk=1
data=2

function saw(x, max)
    max2 = max*2
    y = x % max2
    if y > max then
        return max2 - y
    else
        return y
    end
end

i=1000
function rainbow()
    i = i + 1
    r = saw(i,       255)
    g = saw(i +  85, 255)
    b = saw(i + 170, 255)
    a = 31
    abgr = string.char(a, b, g, r)
    apa102.write(clk, data, abgr)
    tmr.alarm(1, 1, tmr.ALARM_SINGLE, rainbow)
end

rainbow()


