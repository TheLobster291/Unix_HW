// include Vircon libraries
#include "video.h"
#include "audio.h"

// our program starts at the main function
void main( void )
{   
    // -----------------------------
    // PART 1: PREPARE OUR IMAGE
    
    // select our only texture
    select_texture( 0 );
    
    // delimit region number 0 in that texture
    // setting its hotspot at the region's center
    select_region( 0 );
    define_region( 0,0,  349,149,  225,125 );
    
    // -----------------------------
    // PART 2: DRAW ON SCREEN
    
    // clear the screen in some visible color
    clear_screen( color_red );
    
    // draw our region 0 at the center of the screen
    draw_region_at( screen_width/2, screen_height/2 );
    
    //drawing place to write
    set_drawing_point( 100, 30 );
    print( "I wake up and say..." );
    
    // -----------------------------
    // PART 3: PLAY THE SOUND
    
    // play our only sound (number 0), and let a
    // sound channels be automatically selected for it
    play_sound( 0 );
}
