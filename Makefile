C = g++
CFLAGS = -Wall -g -std=c++23 -o 

example_input_string:
	${C} ${CFLAGS} input_string example/tools/input_string.cpp 

example_input_integer:
	${C} ${CFLAGS} input_integer example/tools/input_integer.cpp 

example_console_helper_termios:
	${C} ${CFLAGS} console_helper_termios example/tools/console_helper_termios.cpp 

example_random_string:
	${C} ${CFLAGS} random_string example/tools/random/string.cpp 

example_random_integer:
	${C} ${CFLAGS} random_integer example/tools/random/integer.cpp 

example_memusage:
	${C} ${CFLAGS} memusage example/hwmon/memusage.cpp 

example_battery:
	${C} ${CFLAGS} battery example/hwmon/battery.cpp 

example_cpuusage:
	${C} ${CFLAGS} cpuusage example/hwmon/cpuusage.cpp 

example_serial:
	${C} ${CFLAGS} serial example/buffer/serial.cpp 

example_onetimepin:
	${C} ${CFLAGS} onetimepin example/buffer/oneTimePin.cpp 

examples: example_memusage example_battery \
 example_cpuusage example_serial example_onetimepin \
 example_input_string example_input_integer \
 example_console_helper_termios

