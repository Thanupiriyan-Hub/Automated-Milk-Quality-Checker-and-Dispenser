  
void InputNumber() {
    // Read the keypad input
 key = keypad.getKey(); 
  if (key != NO_KEY) {
    if (key >= '0' && key <= '9') {
      buffer[bufferIndex] = key;
      bufferIndex++;
      
      // Check if two digits have been entered
      if (bufferIndex >= 2) {
        buffer[bufferIndex] = '\0'; // Add null terminator to mark the end of the string
        value = atoi(buffer); // Convert the buffer to an integer
        
        // Validate the entered value
        if (value >= 10 && value <= 99) {
          Serial.print("Entered Value: ");
          Serial.println(value);
        } else {
          Serial.println("Invalid Value!");
        }
        
        bufferIndex = 0; // Reset the buffer index for the next input
      }
      
      delay(100); // Debounce delay
    }
  }
}
