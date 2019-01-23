#include "main.h"

#include <cstdio>

#include "pros/apix.h"

#include "globals.h"

static const int ADI_COLOR_SWITCH = 1;

//runs before initialize
class PreConfig {
    public:
        PreConfig(){
            //disable COBS (serial output formatting)
            serctl(SERCTL_DISABLE_COBS, NULL);

            //clear buffers
            fflush(stdin);
            fflush(stdout);
        }
} conf;

void registerColor(){
    using namespace pros::c;

    adi_port_set_config(ADI_COLOR_SWITCH, E_ADI_DIGITAL_IN);

    if(adi_digital_read(ADI_COLOR_SWITCH)){
        TEAM_COLOR = RED; 
        LV_TEAM_COLOR = LV_COLOR_RED; 
        puts("Registered as RED");
        return;
    }
    puts("Registered as BLUE");
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize(){
    registerColor();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
