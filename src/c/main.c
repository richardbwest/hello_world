#include <pebble.h>
// Include the Pebble SDK header - gives us access to all Pebble functions and types

static Window *s_main_window;
// Declare a static variable to store our main window - static means it's only accessible in this file

static TextLayer *s_text_layer;
// Declare a static variable to store our text layer - this is where we'll display our text

static void main_window_load(Window *window) {
  // This function gets called automatically when the window loads - perfect place to set up UI elements
  
  // Get window bounds
  Layer *window_layer = window_get_root_layer(window);
  // Get the root layer of the window - this is the base layer we can add other layers to
  
  GRect bounds = layer_get_bounds(window_layer);
  // Get the bounds (position and size) of the window - we'll use this to center our text

  // Create text layer with increased height for two lines
  s_text_layer = text_layer_create(GRect(0, bounds.size.h/2 - 30, bounds.size.w, 60));
  // Create a text layer at x=0, y=half screen height minus 30 pixels, full width, 60 pixels tall
  // GRect creates a rectangle: (x, y, width, height)

  // Set larger font
  text_layer_set_font(s_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  // Set the font to Gothic 28 Bold - a nice large, bold system font
  
  // Center align the text
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  // Center the text horizontally within the text layer
  
  // Set text on two lines
  text_layer_set_text(s_text_layer, "Hello,\nWorld!");
  // Set the text content - \n creates a new line, so "Hello," is on line 1 and "World!" on line 2


  // Add to window
  layer_add_child(window_layer, text_layer_get_layer(s_text_layer));
  // Add the text layer to the window so it actually appears on screen
} 

static void main_window_unload(Window *window) {
  // This function gets called when the window unloads - perfect place to clean up memory
  
  text_layer_destroy(s_text_layer);
  // Destroy the text layer to free up memory - important to prevent memory leaks!
}

static void init() {
  // This function initializes our app - sets up everything we need
  
  s_main_window = window_create();
  // Create a new window object and store it in our variable
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    // Set up event handlers - these functions get called at specific times
    .load = main_window_load,
    // When the window loads, call our main_window_load function
    
    .unload = main_window_unload
    // When the window unloads, call our main_window_unload function
  });

  window_stack_push(s_main_window, true);
  // Push the window onto the window stack - this makes it visible! true means animate the transition
}

static void deinit() {
  // This function cleans up when the app closes - frees all allocated memory
  
  window_destroy(s_main_window);
  // Destroy the window to free up memory
}

int main(void) {
  // This is the entry point of our app - the first function that runs when the app starts
  
  init();
  // Call init() to set up our window and UI elements
  
  app_event_loop();
  // Start the event loop - this keeps the app running and handles button presses, etc.
  // This function blocks until the app exits
  
  deinit();
  // After the event loop exits, clean up with deinit()
}

