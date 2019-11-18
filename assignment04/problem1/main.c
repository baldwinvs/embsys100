#define RCC_BASE 0x40023800
#define RCC_AHB1ENR_ADDR_OFFSET 0x30

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER_ADDR_OFFSET 0x00
#define GPIOA_ODR_ADDR_OFFSET 0x14

#define PERIPHERAL_BIT_BAND_ALIAS_BASE 0x40000000
#define PERIPHERAL_BIT_BAND_BASE 0x42000000

#define RCC_AHB1ENR_GPIOA_EN (*(unsigned int*)(PERIPHERAL_BIT_BAND_BASE + \
                             ((RCC_BASE - PERIPHERAL_BIT_BAND_ALIAS_BASE + RCC_AHB1ENR_ADDR_OFFSET) * 32) + (0 * 4)))
#define GPIOA_MODER5_BIT0 (*(unsigned int*)(PERIPHERAL_BIT_BAND_BASE + \
                          ((GPIOA_BASE - PERIPHERAL_BIT_BAND_ALIAS_BASE + GPIOA_MODER_ADDR_OFFSET) * 32) + (10 * 4)))
#define GPIOA_ODR_BIT_5 (*(unsigned int*)(PERIPHERAL_BIT_BAND_BASE + \
                        ((GPIOA_BASE - PERIPHERAL_BIT_BAND_ALIAS_BASE + GPIOA_ODR_ADDR_OFFSET) * 32) + (5 * 4)))

#define GPIOA_ODR (*(unsigned int*)(GPIOA_BASE + GPIOA_ODR_ADDR_OFFSET))
#define GPIOA (1<<5)

volatile int counter=0;

void main(void)
{
    RCC_AHB1ENR_GPIOA_EN = 0x1;
    GPIOA_MODER5_BIT0 = 0x1;

    while(1)
    {
    counter=0;

    while (counter < 1000000)
    {
      counter++;
    }
    //WRITE DIRECTLY TO ALIASED BIT
    GPIOA_ODR_BIT_5 = 0x1;

    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
    //READ, MODIFY, WRITE
    GPIOA_ODR ^= GPIOA;

    }
}
