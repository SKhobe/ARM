/* This code uses a sliding window average filter, which keeps a running sum of 
the last WINDOW_SIZE ADC values and updates the sum whenever a new value is read. 
The filtered value is then simply the sum divided by the window size. This method 
has a time complexity of O(1) for each value, making it very efficient.

You can adjust the WINDOW_SIZE to change the strength of the filter. 
A larger window size will result in a stronger filter, but will also have a slower response time. */






#define WINDOW_SIZE 10

int adc_values[WINDOW_SIZE]; // buffer to store the last WINDOW_SIZE ADC values
int filtered_value = 0; // variable to store the filtered value

// function to update the filtered value
void update_filtered_value(int new_adc_value) {
  // subtract the oldest value from the running sum
  filtered_value -= adc_values[next_index];
  // store the new value in the buffer
  adc_values[next_index] = new_adc_value;
  // add the new value to the running sum
  filtered_value += new_adc_value;
  // increment the index for the next insertion
  next_index = (next_index + 1) % WINDOW_SIZE;
}

int main(void) {
  // initialize the buffer and filtered value
  for (int i = 0; i < WINDOW_SIZE; i++) {
    adc_values[i] = 0;
  }
  filtered_value = 0;

  // read ADC values and update the filtered value
  while (1) {
    int adc_value = read_adc(); // function to read the ADC value
    update_filtered_value(adc_value);
  }

  return 0;
}












