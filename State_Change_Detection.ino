void setup() {
    asm volatile (
        " .equ PINB,0x03              \n" 
        " .equ DDRB,0x04              \n" 
        " .equ PORTB,0x05             \n" 
        
        " in DDRB, 12                 \n"
        " ldi r17,0b00001111          \n" 
        " out DDRB,r17                \n"
        // Here, we define our relevant ports. Since this project uses the B port, we activate the B port.
        
        " ldi r18, 0b00000000         \n"  
        // Define the register to keep track of the number of button presses.
 
        "main_loop:                   \n"
        " sbic PINB, 4                \n"  
        " rjmp button_release_control  \n"
        " jmp main_loop               \n"   
        // If the button is pressed, it goes to the button release control; otherwise, it stays in the loop until pressed.
      
        " button_release_control : \n"
        "sbis PINB,4 \n"
        "jmp increase_button_press \n"
        "jmp button_release_control \n"
        // If the button is released, it goes to the function that increases the button press count; otherwise, it waits until release.
     
        "increase_button_press:       \n"   
        " inc r18                     \n"  // Increase the register designated for the button press count.
        " cpi r18, 0b00000000         \n"  // Check if the button press count register is zero.
        " breq led1_on                \n"  // If the condition is met, go to the function to turn on LED1.
        " cpi r18, 0b00000011         \n"  // Check if the button press count is 3.
        " breq count_zero             \n"  // If the previous condition is met, go to the function to reset the counter.
        " jmp led2_on                 \n"  // Otherwise, go to the function to light up the second LED.

        "count_zero:                  \n" // Reset the counter tracking button presses.
        " ldi r18, 0b00000000         \n"  
        " jmp led1_on                 \n" 

        "led1_on:                     \n"
        "ldi r17,0b00000001 		  \n" // Turn on LED1 by setting the first pin of the respective port to 1.
        " out PORTB,r17 			  \n" // Update the register on the port.
        " jmp main_loop               \n" // Return to the main loop.

        "led2_on:                   \n"
        "ldi r17,0b00000010 		\n" // Turn on LED2 by setting the second pin of the respective port to 1.
        " out PORTB,r17 			\n" // Update the register on the port.             
        " jmp main_loop             \n" // Return to the main loop.
    );
}

void loop() {}
