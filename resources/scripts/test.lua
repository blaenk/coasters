print 'testing!'

local ffi = require('ffi')

ffi.cdef([[
void testfunc();
int get2();
]])

local api = ffi.load("bindings")

api.testfunc()
local two = api.get2()

io.write('got ', two, '!\n')
