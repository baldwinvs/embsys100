#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

// HW REGISTERS
#define GPIOA_BASE          (0x40020000UL)
#define RCC_BASE            (0x40023800UL)

#define GPIOA_MODER         (*(uint32_t*)(GPIOA_BASE + 0x0UL))
#define GPIOA_ODR           (*(uint32_t*)(GPIOA_BASE + 0x14UL))

#define RCC_AHB1ENR         (*(uint32_t*)(RCC_BASE + 0x30UL))

// MORSE CODE STUFF
#define UNIT (500000UL)    // The "unit" that timing is based on.
#define DOT  (1UL)
#define DASH (3UL)
#define NONE (0UL)
#define BETWEEN_PARTS   (1UL)
#define BETWEEN_LETTERS (3UL)
#define BETWEEN_WORDS   (7UL)
#define MAX_PARTS (4)       // The maximum parts of morse code for the alphabet.

#define FOREVER for(;;)

//! The letter sequence in morse code.
typedef struct {
    uint32_t sequence[MAX_PARTS];
} LETTER;

//! The alphabet in morse code.
LETTER letters[26] = {
    {DOT, DASH, NONE, NONE},  // A
    {DASH, DOT, DOT, DOT},    // B
    {DASH, DOT, DASH, DOT},   // C
    {DASH, DOT, DOT, NONE},   // D
    {DOT, NONE, NONE, NONE},  // E
    {DOT, DOT, DASH, DOT},    // F
    {DASH, DASH, DOT, NONE},  // G
    {DOT, DOT, DOT, DOT},     // H
    {DOT, DOT, NONE, NONE},   // I
    {DOT, DASH, DASH, DASH},  // J
    {DASH, DOT, DASH, NONE},  // K
    {DOT, DASH, DOT, DOT},    // L
    {DASH, DASH, NONE, NONE}, // M
    {DASH, DOT, NONE, NONE},  // N
    {DASH, DASH, DASH, NONE}, // O
    {DOT, DASH, DASH, DOT},   // P
    {DASH, DASH, DOT, DASH},  // Q
    {DOT, DASH, DOT, NONE},   // R
    {DOT, DOT, DOT, NONE},    // S
    {DASH, NONE, NONE, NONE}, // T
    {DOT, DOT, DASH, NONE},   // U
    {DOT, DOT, DOT, DASH},    // V
    {DOT, DASH, DASH, NONE},  // W
    {DASH, DOT, DOT, DASH},   // X
    {DASH, DOT, DASH, DASH},  // Y
    {DASH, DASH, DOT, DOT}    // Z
};

/** Wait for (multiplier * UNIT) iterations.
 *
 * @param multiplier The UNIT multiplier.
 */
void wait(const uint32_t multiplier) {
    volatile uint32_t count = UNIT * multiplier;
    while(count > 0) {
        --count;
    }
}

/** Initialize the hardware registers in preparation of using LD2.
 */
void initLD2() {
    // write 0x1 to RCC_AHB1ENR to enable the clock for GPIOA
    RCC_AHB1ENR |= 0x1UL;
    // set MODER5 to general purpose output mode (write 0x400) in GPIOA_MODER
    GPIOA_MODER |= 0x400UL;
}

/** Toggle LD2 from ON->OFF or OFF->ON state.
 */
void toggleLD2() {
    // set ODR5 bit (0x20) in GPIOA_ODR register to turn on LD2, clear to turn off.
    GPIOA_ODR ^= 0x20UL;
}

int main()
{
    initLD2();

    const char* name = "Victor";
    const size_t sz = strlen(name);

    FOREVER {
        for(size_t i = 0; i < sz; i++) {
            char character = toupper(name[i]);
            LETTER* letter = &letters[character - 'A'];
            for(size_t j = 0; j < MAX_PARTS; j++) {
                toggleLD2();
                wait(letter->sequence[j]);
                // Check if there are more parts to the sequence.
                if(j+1 < MAX_PARTS && letter->sequence[j+1] != NONE) {
                    toggleLD2();
                    wait(BETWEEN_PARTS);
                }
                else {
                    toggleLD2();
                    break;
                }
            }

            // Check if there are more letters.
            if(i+1 < sz) {
                wait(BETWEEN_LETTERS);
            }
        }

        wait(BETWEEN_WORDS);
    }
    return 0;
}
