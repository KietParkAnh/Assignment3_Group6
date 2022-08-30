#include "uart.h"
#include "mbox.h"
#include "framebf.h"
#include "printf.h"
#include "image.h"
#include "video.h"
#include "largeImage.h"
#include "game.h"

void main()
{
    int count = 0;

    uart_init();

    // say welcome message
    uart_puts("ooooooooooo ooooooooooo ooooooooooo ooooooooooo   ooooooo         o88  ooooooo     ooooooo\n");
    uart_puts(" 888    88   888    88   888    88  88  888  88 o88     888     o8888 888    88o o888  o888o\n");
    uart_puts(" 888ooo8     888ooo8     888ooo8        888           o888    o88 888  888oo8888 888  8  888\n");
    uart_puts(" 888    oo   888    oo   888    oo      888        o888   o o888oo888oo     888  888o8  o888\n");
    uart_puts("o888ooo8888 o888ooo8888 o888ooo8888    o888o    o8888oooo88      o888o   o888      88ooo88\n");
    uart_puts("\n");
    uart_puts("oooo     oooo ooooooooooo ooooo         oooooooo8   ooooooo  oooo     oooo ooooooooooo   ooooooooooo   ooooooo\n");
    uart_puts(" 88   8   88   888    88   888        o888     88 o888   888o 8888o   888   888    88    88  888  88 o888   888o\n");
    uart_puts("  88 888 88    888ooo8     888        888         888     888 88 888o8 88   888ooo8          888     888     888\n");
    uart_puts("   888 888     888    oo   888      o 888o     oo 888o   o888 88  888  88   888    oo        888     888o   o888\n");
    uart_puts("    8   8     o888ooo8888 o888ooooo88  888oooo88    88ooo88  o88o  8  o88o o888ooo8888      o888o      88ooo88\n");
    uart_puts("\n");
    uart_puts("oooooooooo      o      oooooooooo  ooooooooooo       ooooooo    oooooooo8\n");
    uart_puts(" 888    888    888      888    888  888    88      o888   888o 888\n");
    uart_puts(" 888oooo88    8  88     888oooo88   888ooo8        888     888  888oooooo\n");
    uart_puts(" 888    888  8oooo88    888  88o    888    oo      888o   o888         888\n");
    uart_puts("o888ooo888 o88o  o888o o888o  88o8 o888ooo8888       88ooo88   o88oooo888\n");
    uart_puts("\n");
    uart_puts("Developed by Truong Phu Khang - S3814172.\n");

    framebf_init();

    // Print cursor onto terminal screen
    uart_puts("\n");
    uart_puts("MyBareOS> ");

    void draw_image()
    {
        // framebf_init(physicalWidth, physicalHeight, virtualWidth, virtualHeight);
        for (int j = 0; j < 177; j++)
        {
            for (int i = 0; i < 284; i++)
            {
                drawPixelARGB32(i, j, image[j * 284 + i]);
            }
        }
    }

    void draw_pixelBall(int x, int y)
    {
        // framebf_init(pixelBallPhysicalWidth, pixelBallPhysicalHeight, pixelBallVirtualWidth, pixelBallVirtualHeight);
        for (int j = 0; j < 50; j++)
        {
            for (int i = 0; i < 50; i++)
            {
                drawPixelARGB32(i + x, y, pixelball[j * 50 + i]);
            }
        }
    }

    void draw_greenTile(int x, int y)
    {
        // framebf_init(greenTilePhysicalWidth, greenTilePhysicalHeight, greenTileVirtualWidth, greenTileVirtualHeight);
        for (int j = 0; j < 29; j++)
        {
            y++;
            for (int i = 0; i < 123; i++)
            {
                drawPixelARGB32(i + x, y, greenTile[j * 123 + i]);
            }
        }
    }

    void draw_blueTile(int x, int y)
    {
        // framebf_init(blueTilePhysicalWidth, blueTilePhysicalHeight, blueTileVirtualWidth, blueTileVirtualHeight);
        for (int j = 0; j < 29; j++)
        {
            y++;
            for (int i = 0; i < 123; i++)
            {
                drawPixelARGB32(i + x, y, bluetile[j * 123 + i]);
            }
        }
    }

    void draw_yellowTile(int x, int y)
    {
        // framebf_init(yellowTilePhysicalWidth, yellowTilePhysicalHeight, yellowTitleVirtualWidth, yellowTileVirtualHeight);
        for (int j = 0; j < 29; j++)
        {
            y++;
            for (int i = 0; i < 123; i++)
            {
                drawPixelARGB32(i + x, y, yellowtile[j * 123 + i]);
            }
        }
    }

    void draw_redTile(int x, int y)
    {
        // framebf_init(redTilePhysicalWidth, redTilePhysicalHeight, redTileVirtualWidth, redTileVirtualHeight);
        for (int j = 0; j < 29; j++)
        {
            y++;
            for (int i = 0; i < 123; i++)
            {
                drawPixelARGB32(i + x, y, redtile[j * 123 + i]);
            }
        }
    }

    void draw_game()
    {
        // framebf_init(gamePhysicalWidth, gamePhysicalHeight, gameVirtualWidth, gameVirtualHeight);
        for (int x = 50; x < 470; x += 173)
        {
            for (int y = 50; y < 254; y += 29)
            {
                if (y == 50)
                {
                    draw_yellowTile(x, y);
                }
                else if (y == 79)
                {
                    draw_redTile(x, y);
                }
                else if (y == 108)
                {
                    draw_blueTile(x, y);
                }
                else if (y == 137)
                {
                    draw_redTile(x, y);
                }
                else if (y == 166)
                {
                    draw_yellowTile(x, y);
                }
                else if (y == 195)
                {
                    draw_blueTile(x, y);
                }
                else if (y == 224)
                {
                    draw_yellowTile(x, y);
                }
                else if (y == 253)
                {
                    draw_redTile(x, y);
                }
            }
        }
    }

    void draw_video()
    {
        int countFrame = 0;
        // framebf_init(phWidth, phHeight, virWidth, virHeight);
        while (countFrame < 5)
        {
            for (int j = 0; j < 240; j++)
            {
                for (int i = 0; i < 320; i++)
                {
                    if (countFrame == 0)
                    {
                        drawPixelARGB32(i, j, video[j * 320 + i]);
                    }
                    else if (countFrame == 1)
                    {
                        drawPixelARGB32(i, j, video1[j * 320 + i]);
                    }
                    else if (countFrame == 2)
                    {
                        drawPixelARGB32(i, j, video2[j * 320 + i]);
                    }
                    else if (countFrame == 3)
                    {
                        drawPixelARGB32(i, j, video3[j * 320 + i]);
                    }
                    else if (countFrame == 4)
                    {
                        drawPixelARGB32(i, j, video4[j * 320 + i]);
                    }
                    else
                    {
                        uart_puts("No more frame");
                    }
                }
            }
            countFrame++;
        }
    }

    void drawLargeImage()
    {
        char str[10];
        int count = 0, countY = 0, flag = 0;
        // framebf_init(pWidth, pHeight, vWidth, vHeight);
        for (int j = 0; j < 1206; j++)
        {
            for (int i = 0; i < 1000; i++)
            {
                drawPixelARGB32(i, j, largImage[j * 1000 + i]);
            }
        }

        while (1)
        {
            str[count] = uart_getc();

            if (str[count] == 's')
            {
                if (flag <= 500)
                {
                    countY = flag + 100;
                    flag = countY;
                    framebf_init(pWidth, pHeight, vWidth, vHeight);
                    for (int j = 0; j < 1206; j++)
                    {
                        countY++;
                        for (int i = 0; i < 1000; i++)
                        {
                            drawPixelARGB32(i, j, largImage[countY * 1000 + i]);
                        }
                    }
                }
            }

            if (str[count] == 'w')
            {
                if (flag > 0)
                {
                    countY = flag - 100;
                    flag = countY;
                    framebf_init(pWidth, pHeight, vWidth, vHeight);
                    for (int j = 0; j < 1206; j++)
                    {
                        countY++;
                        for (int i = 0; i < 1000; i++)
                        {
                            drawPixelARGB32(i, j, largImage[countY * 1000 + i]);
                        }
                    }
                }
            }
            count++;
        }
    }

    // Comparing string function
    int strCompare(char *arrayA, char *arrayB)
    {
        int count = 0, anw = 0;
        // Looping all character in arrayB
        while (arrayB[count] != '\0')
        {
            // Comparing character by character between arrayA and arrayB.
            if (arrayA[count] == arrayB[count])
            {
                // Set value anw = 0 as true.
                anw = 0;
                // continue checking until while loop condition reached.
                count++;
            }
            else
            {
                // Set value anw = 1 as false.
                anw = 1;
                // stop loop
                break;
            }
        }
        // return result/
        return anw;
    }

    // Function display all information of all command in CLI.
    void helpCommand(char *array)
    {
        // Condition to distinguish between help and help <command>.
        if (array[4] == '\n')
        {
            // print out all command exist in the Bare OS.
            uart_puts("\nFor more information on a specific command, type help command-name\n");
            uart_puts("help <command_name>      Show full information of the command.\n");
            uart_puts("help                     Show brief information of all commands.\n");
            uart_puts("setcolor                 Set  text  color,  and/or  background  color  of  the console  to  one  of  the  following  color:  BLACK,  RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE.\n");
            uart_puts("brdev                    Show board revision.\n");
            uart_puts("scrsize                  Set screen size. Must have options to set physical screen size (-p) or virtual screen size (-v), or both (by default).\n");
            uart_puts("clk                      Show clock rate.\n");
            uart_puts("ARM                      Show ARM Memory.\n");
            uart_puts("draw                     Draw 6 rectangle with 6 different color(RED, GREEN, BLUE, PRUPLE, ORANGE).\n");
            uart_puts("MAC                      Show MAC address.\n");
            uart_puts("clear                    Clear terminal console screen.\n");
        }
        else
        {
            int count = 4, i = 0;
            char command[50];
            // looping through each character in array.
            while (array[count] != '\n')
            {
                // uart_sendc(array[count]);
                // Get specific command that users want to learn more informations.
                command[i] = array[count];
                // uart_sendc(command[i]);
                i++;
                count++;
            }

            // Find correct information to a corresponding to command.
            if (strCompare(command, "setcolor") == 0)
            {
                uart_puts("Set text color only:                         setcolor -t <color>.\n");
                uart_puts("Set background color only:                   setcolor -b <color>.\n");
                uart_puts("Set color for both background and text:      setcolor -t <color> -b <color or setcolor -b <color> -t<color>.\n");
                uart_puts("Accepted color and writing format:  Black,  Red, Green, Yellow, Blue, Purple, Cyan, White.\n");
            }
            else if (strCompare(command, "brdev") == 0)
            {
                uart_puts("Show board revision:                         brdev\n");
            }
            else if (strCompare(command, "scrsize") == 0)
            {
                uart_puts("Set screen size for virtual screen:          scrsize -v <width> <height>.\n");
                uart_puts("Set screen size for physical screen:         scrsize -p <width> <height>.\n");
                uart_puts("Set screen size for both screens:            scrsize -v <width> <height> -p <width> <height> or scrsize -p <width> <height> -v <width> <height\n");
            }
            else if (strCompare(command, "clk") == 0)
            {
                uart_puts("Show clock rate:                             clk\n");
            }
            else if (strCompare(command, "ARM") == 0)
            {
                uart_puts("Show ARM memory:                             ARM\n");
            }
            else if (strCompare(command, "draw") == 0)
            {
                uart_puts("Show drawed image:                           draw.\n");
                uart_puts("Draw 6 rectangles with 6 different colors(RED, GREEN, BLUE, PRUPLE, ORANGE).\n");
            }
            else if (strCompare(command, "MAC") == 0)
            {
                uart_puts("Show MAC address:                            MAC\n");
            }
            else
            {
                uart_puts("Commnad name is not valid or not avaliable.\n");
            }
        }
    }

    // Clean CLI screen function.
    void clear()
    {
        uart_puts("\e[1;1H\e[2J");
    }

    // Show clock rate of the board.
    void showClockRate()
    {
        mbox[0] = 8 * 4;        // Message Buffer Size in bytes (8 elements * 4 bytes (32 bit) each)
        mbox[1] = MBOX_REQUEST; // Message Request Code (this is a request message)
        mbox[2] = 0x00030002;   // TAG Identifier: Get clock rate
        mbox[3] = 8;            // Value buffer size in bytes (max of request and response lengths)
        mbox[4] = 0;            // REQUEST CODE = 0
        mbox[5] = 3;            // clock id: ARM system clock
        mbox[6] = 0;            // clear output buffer (response data are mbox[5] & mbox[6])
        mbox[7] = MBOX_TAG_LAST;

        if (mbox_call(ADDR(mbox), MBOX_CH_PROP))
        {
            uart_puts("DATA: ARM clock rate = ");
            uart_dec(mbox[6]);
            uart_puts("\n");
        }
    }

    // Show Board Revision.
    void showBoardRevision()
    {
        mbox[0] = 8 * 4;        // Message Buffer Size in bytes (8 elements * 4 bytes (32 bit) each)
        mbox[1] = MBOX_REQUEST; // Message Request Code (this is a request message)
        mbox[2] = 0x00010002;   // TAG Identifier: Get board revision
        mbox[3] = 32;           // Value buffer size in bytes (max of request and response lengths)
        mbox[4] = 0;            // REQUEST CODE = 0
        mbox[5] = 4;            // RESPOND LENGTH = 4
        mbox[6] = 0;            // clear output buffer (response data are mbox[5] & mbox[6])
        mbox[7] = MBOX_TAG_LAST;

        if (mbox_call(ADDR(mbox), MBOX_CH_PROP))
        {
            uart_puts("DATA: Board Revision = ");
            uart_dec(mbox[6]);
            uart_puts("\n");
        }
    }

    // Show Board Model.
    void showARMMemory()
    {
        mbox[0] = 8 * 4;        // Message Buffer Size in bytes (8 elements * 4 bytes (32 bit) each)
        mbox[1] = MBOX_REQUEST; // Message Request Code (this is a request message)
        mbox[2] = 0x00010005;   // TAG Identifier: Get ARM Memory.
        mbox[3] = 32;           // Value buffer size in bytes (max of request and response lengths)
        mbox[4] = 0;            // REQUEST CODE = 0
        mbox[5] = 8;            // RESPOND LENGTH = 4
        mbox[6] = 0;            // clear output buffer (response data are mbox[5] & mbox[6])
        mbox[7] = MBOX_TAG_LAST;

        if (mbox_call(ADDR(mbox), MBOX_CH_PROP))
        {
            uart_puts("DATA: ARM Memory = ");
            uart_dec(mbox[6]);
            uart_puts("\n");
        }
    }

    // Show MAC Address.
    void showMACAddress()
    {
        mbox[0] = 8 * 4;        // Message Buffer Size in bytes (8 elements * 4 bytes (32 bit) each)
        mbox[1] = MBOX_REQUEST; // Message Request Code (this is a request message)
        mbox[2] = 0x00010003;   // TAG Identifier: Get MAC Address.
        mbox[3] = 8;            // Value buffer size in bytes (max of request and response lengths)
        mbox[4] = 0;            // REQUEST CODE = 0
        mbox[5] = 6;            // RESPOND LENGTH = 6
        mbox[6] = 0;            // clear output buffer (response data are mbox[5] & mbox[6])
        mbox[7] = MBOX_TAG_LAST;

        if (mbox_call(ADDR(mbox), MBOX_CH_PROP))
        {
            uart_puts("DATA: MAC Address = ");
            uart_dec(mbox[6]);
            uart_puts("\n");
        }
    }

    // Function allow users to set physical and virtual screen size.
    void setScreenSize(char *array)
    {
        // Decleare all variables.
        // assistance variables.
        int count = 0, check = 1, i = 0, j = 0;

        // Variable to store all 4 values of both physical and virtual
        int phWidth = 0, phHeight = 0;
        int virWidth = 0, virHeight = 0;

        // Identify width or height value for virtual and physical.
        int positionPhysical = 0, positionVirtual = 0;

        // Arrays to store all 4 values of both virtual and physical.
        char physicalWidth[10], physicalHeight[10];
        char virtualWidth[10], virtualHeight[10];

        // Looping through array
        while (array[count] != '\0')
        {
            // checking conditions to identify values for physical or virtual screen also checking for syntax correctness.
            if ((array[count] == '-' && array[count + 1] == 'p') && (array[count + 2] != '\0' || array[count + 2] != ' '))
            {
                // Set check value = 0 to identify code readable
                check = 0;
                // uart_puts("\n");
                // Continue looping through array until it reach the end or next set command
                while ((array[count] != '\0') && (array[count + 1] != '-'))
                {
                    // Conditions to get width and height only
                    if ((array[count] != ' ' && positionPhysical == 0) && (array[count] != '-' && array[count] != 'p'))
                    {
                        // stores physical width value.
                        physicalWidth[i] = array[count];
                        // uart_sendc(physicalWidth[i]);
                        // Convert characters in physicalWidth array into number.
                        for (int k = 48; k <= 57; k++)
                        {
                            // Using ASCII table value to converts characters into number.
                            if (physicalWidth[i] == k)
                            {
                                phWidth = phWidth * 10 + (k - 48);
                            }
                        }
                        // Continue looping.
                        i++;
                        count++;
                        // Condition to identify finished getting width value.
                        if (array[count] == ' ')
                        {
                            positionPhysical = 1;
                        }
                    }
                    // Conditions to get height value only from the array.
                    else if (array[count] != ' ' && positionPhysical == 1)
                    {
                        // Store physical height value.
                        physicalHeight[i] = array[count];
                        // uart_sendc(physicalHeight[i]);
                        // Convert characters in physicalHeight array into number.
                        for (int h = 48; h <= 57; h++)
                        {
                            // Using ASCII table value to converts characters into number.
                            if (physicalHeight[i] == h)
                            {
                                phHeight = phHeight * 10 + (h - 48);
                            }
                        }
                        // Continue looping.
                        i++;
                        count++;
                    }
                    else
                    {
                        // Continue looping until the end.
                        i++;
                        count++;
                    }
                }
            }

            // checking conditions to identify values for physical or virtual screen also checking for syntax correctness.
            if ((array[count] == '-' && array[count + 1] == 'v') && (array[count + 2] != '\0' | array[count + 2] != ' '))
            {
                // Set check value = 0 to identify code readable
                check = 0;
                // uart_puts("\n");
                // Continue looping through array until it reach the end or next set command
                while ((array[count] != '\0') && array[count + 1] != '-')
                {
                    // Conditions to get width and height only
                    if ((array[count] != ' ' && positionVirtual == 0) && (array[count] != '-' && array[count] != 'v'))
                    {
                        // stores virtual width value.
                        virtualWidth[j] = array[count];
                        // uart_sendc(virtualWidth[j]);
                        // Convert characters in virtualWidth array into number.
                        for (int l = 48; l <= 57; l++)
                        {
                            // Using ASCII table value to converts characters into number.
                            if (virtualWidth[j] == l)
                            {
                                virWidth = virWidth * 10 + (l - 48);
                            }
                        }
                        // Continue looping.
                        j++;
                        count++;
                        // Condition to identify finished getting width value.
                        if (array[count] == ' ')
                        {
                            positionVirtual = 1;
                        }
                    }
                    // Conditions to get height value only from the array.
                    else if (array[count] != ' ' && positionVirtual == 1)
                    {
                        // Store virtual height value.
                        virtualHeight[j] = array[count];
                        // uart_sendc(virtualHeight[j]);
                        // Convert characters in virtualHeight array into number.
                        for (int m = 48; m <= 57; m++)
                        {
                            // Using ASCII table value to converts characters into number.
                            if (virtualHeight[j] == m)
                            {
                                virHeight = virHeight * 10 + (m - 48);
                            }
                        }
                        // Continue looping.
                        j++;
                        count++;
                    }
                    else
                    {
                        // Continue looping until the end.
                        j++;
                        count++;
                    }
                }
                // uart_puts("\n");
            }
            // Continue looping until the end.
            count++;
        }

        // Condition to display error message
        if (check == 1)
        {
            uart_puts("Syntax error.\n");
        }

        // Condition to set physical width and height screen.
        if (positionPhysical == 1)
        {
            mbox[0] = 35 * 4;            // Length of message in bytes
            mbox[1] = MBOX_REQUEST;      // Message Request Code (this is a request message)
            mbox[2] = MBOX_TAG_SETPHYWH; // TAG Identifier: Set physical width-height
            mbox[3] = 8;                 // Value size in bytes
            mbox[4] = 0;                 // REQUEST CODE = 0
            mbox[5] = phWidth;           // New width for physical screen
            mbox[6] = phHeight;          // New height for physical screen
            mbox[7] = MBOX_TAG_LAST;
            mbox_call(ADDR(mbox), MBOX_CH_PROP);
        }
        // Condition to set virtual width and height screeen.
        else if (positionVirtual == 1)
        {
            mbox[0] = 35 * 4;             // Length of message in bytes
            mbox[1] = MBOX_REQUEST;       // Message Request Code (this is a request message)
            mbox[2] = MBOX_TAG_SETVIRTWH; // TAG Identifier: set virtual width-height
            mbox[3] = 8;                  // Value size in bytes
            mbox[4] = 0;                  // REQUEST CODE = 0
            mbox[5] = virWidth;           // New width for virtual screen
            mbox[6] = virHeight;          /// New height for virtual screen
            mbox[7] = MBOX_TAG_LAST;
            mbox_call(ADDR(mbox), MBOX_CH_PROP);
        }
        // Display error message when value empty.
        else
        {
            uart_puts("Command missing arguments.\n");
        }
    }

    // Draw rectangle on the screen
    void drawRectangle()
    {
        drawRectARGB32(100, 100, 400, 400, 0x00AA0000, 1); // RED
        drawRectARGB32(150, 150, 400, 400, 0x0000BB00, 1); // GREEN
        drawRectARGB32(200, 200, 400, 400, 0x000000CC, 1); // BLUE
        drawRectARGB32(250, 250, 400, 400, 0x00FFFF00, 1); // YELLOW
        drawRectARGB32(300, 300, 400, 400, 0x007F3FBF, 1); // PURPLE
        drawRectARGB32(350, 350, 400, 400, 0x00F09D0E, 1); // ORANGE
    }

    // Set colors for texts and background.
    void setColor(char *array)
    {
        int count = 0, i = 0, j = 0, check = 1;
        char text[50], bGround[50];
        // looping through each character in array.
        while (array[count] != '\0')
        {
            // uart_sendc(array[count]);
            // Conditions to check command set color for texts.
            if ((array[count] == '-' && array[count + 1] == 't') && (array[count + 2] != '\0'))
            {
                // Variable to check is the command syntax correct or not.
                check = 0;
                // looping through the rest of the array or until hit next set color command for background.
                while ((array[count] != '\0') && (array[count + 1] != '-'))
                {
                    // Get specific color from users command.
                    text[i] = array[count + 2];
                    // printf("%d ", count);
                    // uart_sendc(text[i]);
                    i++;
                    count++;
                }
                // uart_puts("\n");
                // Find correct color that users want to set for texts.
                if (strCompare(text, "Black") == 0)
                {
                    uart_puts("\033[30m");
                }
                else if (strCompare(text, "Red") == 0)
                {
                    uart_puts("\033[31m");
                }
                else if (strCompare(text, "Green") == 0)
                {
                    uart_puts("\033[32m");
                }
                else if (strCompare(text, "Yellow") == 0)
                {
                    uart_puts("\033[33m");
                }
                else if (strCompare(text, "Blue") == 0)
                {
                    uart_puts("\033[34m");
                }
                else if (strCompare(text, "Purple") == 0)
                {
                    uart_puts("\033[35m");
                }
                else if (strCompare(text, "Cyan") == 0)
                {
                    uart_puts("\033[36m");
                }
                else if (strCompare(text, "White") == 0)
                {
                    uart_puts("\033[37m");
                }
                else
                {
                    uart_puts("Color is not valid.\n");
                    break;
                }
            }

            // Conditions to check command set color for background.
            if ((array[count] == '-' && array[count + 1] == 'b') && (array[count + 2] != '\0'))
            {
                // Variable to check is the command syntax correct or not.
                check = 0;
                while ((array[count] != '\0') && (array[count + 1] != '-'))
                {
                    // Get specific color from users command.
                    bGround[j] = array[count + 2];
                    // uart_sendc(bGround[j]);
                    j++;
                    count++;
                }
                // uart_puts("\n");
                // Find correct color that users want to set for background.
                if (strCompare(bGround, "Black") == 0)
                {
                    uart_puts("\033[40m");
                }
                else if (strCompare(bGround, "Red") == 0)
                {
                    uart_puts("\033[41m");
                }
                else if (strCompare(bGround, "Green") == 0)
                {
                    uart_puts("\033[42m");
                }
                else if (strCompare(bGround, "Yellow") == 0)
                {
                    uart_puts("\033[43m");
                }
                else if (strCompare(bGround, "Blue") == 0)
                {
                    uart_puts("\033[44m");
                }
                else if (strCompare(bGround, "Purple") == 0)
                {
                    uart_puts("\033[45m");
                }
                else if (strCompare(bGround, "Cyan") == 0)
                {
                    uart_puts("\033[46m");
                }
                else if (strCompare(bGround, "White") == 0)
                {
                    uart_puts("\033[47m");
                }
                else
                {
                    uart_puts("Color is not valid.\n");
                    break;
                }
            }
            count++;
        }
        // Condition to display syntax error message to users.
        if (check == 1)
        {
            uart_puts("Syntax error.\n");
        }
    }

    // Direct Users to correct function corresponding to commands.
    int selectCommmand(char *array)
    {
        int checkScrSize = 0;
        // Condition to be taken to helpCommand function.
        if (strCompare(array, "help") == 0)
        {
            helpCommand(array);

            // Condition to be taken to clear function.
        }
        else if (strCompare(array, "clear") == 0)
        {
            // Extra condition to check syntax of users's input commands.
            if (array[5] == '\n')
            {
                clear();
            }
            else
            {
                uart_puts("Command line syntax error.\n");
            }

            // Condition to be taken to showBoardRevision function.
        }
        else if (strCompare(array, "brdev") == 0)
        {
            // Extra condition to check syntax of users's input commands.
            if (array[5] == '\n')
            {
                showBoardRevision();
            }
            else
            {
                uart_puts("Command line syntax error.\n");
            }

            // Condition to be taken to showClockRate function.
        }
        else if (strCompare(array, "clk") == 0)
        {
            // Extra condition to check syntax of users's input commands.
            if (array[3] == '\n')
            {
                showClockRate();
            }
            else
            {
                uart_puts("Command line syntax error.\n");
            }

            // Condition to be taken to showARMMemory function.
        }
        else if (strCompare(array, "ARM") == 0)
        {
            // Extra condition to check syntax of users's input commands.
            if (array[3] == '\n')
            {
                showARMMemory();
            }
            else
            {
                uart_puts("Command line syntax error.\n");
            }

            // Condition to be taken to showMACAddress function.
        }
        else if (strCompare(array, "MAC") == 0)
        {
            // Extra condition to check syntax of users's input commands.
            if (array[3] == '\n')
            {
                showMACAddress();
            }
            else
            {
                uart_puts("Command line syntax error.\n");
            }

            // Condition to be taken to drawRectangle function.
        }
        else if (strCompare(array, "draw") == 0)
        {
            // Extra condition to check syntax of users's input commands.
            if (array[4] == '\n')
            {
                drawRectangle();
            }
            else
            {
                uart_puts("Command line syntax error.\n");
            }

            // Condition to be taken to setColor function.
        }
        else if (strCompare(array, "setcolor") == 0)
        {
            setColor(array);

            // Condition to be taken to scrsize function.
        }
        else if (strCompare(array, "scrsize") == 0)
        {
            // return value checkScrSize when users call scrsize command.
            checkScrSize = 1;
            // setScreenSize(array);
        }
        else if (strCompare(array, "img") == 0)
        {
            draw_image();
        }
        else if (strCompare(array, "video") == 0)
        {
            while (1)
            {
                draw_video();
            }
        }
        else if (strCompare(array, "Image") == 0)
        {
            drawLargeImage();
        }
        else if (strCompare(array, "game") == 0)
        {
            draw_game();
            // draw_backGround();
            // draw_pixelBall();
            // draw_blueTile();
            // Note: greenTile turn to blue
            // draw_greenTile();
            // draw_yellowTile();
            // draw_redTile();
        }
        else
        {
            // Diplay error message to users.
            uart_puts("Can't understand the command.\n");
        }
        return checkScrSize;
    }

    // Clear white space within each command from users.
    void clearWhiteSpace(char *array)
    {
        int countArr = 0, countCl = 0, check = 0;
        char clearWhiteSpace[60];
        // Looping through array.
        while (array[countArr] != '\0')
        {
            // Check character by character for white-spaces character
            if (array[countArr] != ' ')
            {
                // Get each character from the command to clearWhiteSpace array.
                clearWhiteSpace[countCl] = array[countArr];
                // uart_sendc(clearWhiteSpace[countCl]);
                // continue task.
                countCl++;
                countArr++;
            }
            else
            {
                // If character is white-space, continue counting as skipping that character.
                countArr++;
            }
        }
        // Get checkScrSize value from selectCommand function.
        check = selectCommmand(clearWhiteSpace);
        // Check if users is calling scrsize.
        if (check == 1)
        {
            // Using array without white-space cleared for setScreenSize function.
            setScreenSize(array);
        }
    }

    // echo everything back
    while (1)
    {
        char str[60];
        // read each char
        str[count] = uart_getc();
        uart_sendc(str[count]);
        // Detect "Enter" key-press.
        if (str[count] == '\n')
        {
            count = 0;
            // Call function clearWhiteSpace to errase white-space in users input arrary.
            clearWhiteSpace(str);
            // print custom cursor.
            uart_puts("MyBareOS> ");
            // convertCharToInt();
        }
        else
        {
            // continue reading users input if users hasn't pressed enter.
            count++;
        }
    }
}