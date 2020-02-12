#include <Control_Surface.h> // Include the Control Surface library

// Instantiate a MIDI over USB interface
USBMIDI_Interface midi;

// Instantiate four Banks, with two tracks per bank. 
// Compare these numbers to the diagram above.
Bank<16> bank(1);
//   │       └───── number of tracks per bank
//   └───────────── number of banks

// Instantiate a Bank selector to control which one of the four Banks is active.
IncrementDecrementSelector<16> selector = {
    bank,       // Bank to manage
    {2, 3},     // push button pins (increment, decrement)
    Wrap::Wrap, // Wrap around
};

// Wrapping around means that if you're in Bank 4 and you press the increment 
// button, you wrap back around to Bank 1. Similarly, if you're in Bank 1 and
// you press the decrement button, you wrap back around to Bank 4.
// The alternative to Wrap::Wrap is Wrap::Clamp. In that case, pressing the 
// increment button when you're in Bank 4 won't do anything, you'll stay in 
// Bank 4. If you're in Bank 1 and press the decrement button, you'll stay in 
// Bank 1.

// Instantiate two potentiometers for the volume controls.
Bankable::CCPotentiometer fader1 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A0,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_1}, // address
};
Bankable::CCPotentiometer fader2 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A1,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_2}, // address
};

Bankable::CCPotentiometer fader3 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A2,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_3}, // address
};
Bankable::CCPotentiometer fader4 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A3,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_4}, // address
};

Bankable::CCPotentiometer fader5 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A4,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_5}, // address
};
Bankable::CCPotentiometer fader6 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A5,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_6}, // address
};

Bankable::CCPotentiometer fader7 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A6,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_7}, // address
};
Bankable::CCPotentiometer fader8 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A7,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_8}, // address
};

Bankable::CCPotentiometer fader9 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A8,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_9}, // address
};
Bankable::CCPotentiometer fader10 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A9,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_10}, // address
};

Bankable::CCPotentiometer fader11 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A10,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_11}, // address
};
Bankable::CCPotentiometer fader12 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A11,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_12}, // address
};

Bankable::CCPotentiometer fader13 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A12,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_13}, // address
};
Bankable::CCPotentiometer fader14 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A13,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_14}, // address
};

Bankable::CCPotentiometer fader15 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A14,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_15}, // address
};
Bankable::CCPotentiometer fader16 = {
  {bank, BankType::CHANGE_CHANNEL},     // bank configuration
  A15,                                   // analog pin
  {MIDI_CC::Channel_Volume, CHANNEL_16}, // address
};


void setup() {
  Control_Surface.begin(); // Initialize Control Surface
}

void loop() {
  Control_Surface.loop(); // Update the Control Surface
}
