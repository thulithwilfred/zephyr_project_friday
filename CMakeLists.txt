#Setting to exclusively build for the Particle Boron
set(BOARD particle_boron)
# Find Zephyr. This also loads Zephyr's build system.
cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr)
project(my_zephyr_app)

#Adding include directory for mylib
include_directories(src/lib/
					src/
					)
		

#Adding Source Files to the "app" target, must be placed after
# find_package(Zephyr) which defines the target.

target_sources(app PRIVATE 
		   src/main.c
	       src/lib/ssd1306/ssd1306.c
	       src/lib/ssd1306/fonts.c
		   src/lib/ssd1306/ssd1306_thread.c
		   src/lib/debug_leds/debug_leds.c
		   src/lib/uart0_serial/uart0_serial.c
	       )
