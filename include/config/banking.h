#ifndef GUARD_CONFIG_BANKING_H
#define GUARD_CONFIG_BANKING_H

#define SAVINGS_ENABLED          FALSE // Enables the GSC/HGSS savings feature
#define SAVINGS_FLAG             0     // Flag used to toggle savings on/off
#define SAVINGS_PERCENT          25    // Percentage of money saved after battle (Rounded Down)

// When the saved money in the bank reaches a multiple of this value
// an item from sRepeatedPurchaseTable will be purchased.
//INFO: https://bulbapedia.bulbagarden.net/wiki/Mom_(Johto)#Items_purchased
#define REPEAT_PURCHASE_MULT     3000

#endif // GUARD_CONFIG_BANKING_H
