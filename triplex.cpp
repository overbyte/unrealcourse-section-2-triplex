#include <iostream>
#include <ctime>

bool PlayGame(int Difficulty);
bool TestWinCondition();
void OutputIntro();
void InputPlayerGuess();
void ResetStdIn();

const int TotalGuesses = 3;

int GuessA, GuessB, GuessC;
int GuessSum, GuessProduct;
int CurrentGuess = 0;
int bLevelComplete = false;

int main() 
{
    OutputIntro();

    const int MaxDifficulty = 5;
    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bLevelComplete = PlayGame(LevelDifficulty);

        if (CurrentGuess > TotalGuesses)
        {
            std::cout << "<<< SECURITY HAS BEEN ALERTED TO YOUR PRESCENCE >>>\n";
            std::cout << "You ran out of time but you'll have plenty of time ";
            std::cout << "to think about it behind bars. Better luck next time, eh?";

            return 0;
        }

        ResetStdIn();

        if (bLevelComplete)
        {
            CurrentGuess = 0;
            ++LevelDifficulty;
        }
    }

    std::cout << "*** YOU DID IT!! Now grab your spoils and get out of there! ***\n\n";

    std::cout << "    .o oOOOOOOOo                                            OOOo\n";
    std::cout << "    Ob.OOOOOOOo  OOOo.      oOOo.                      .adOOOOOOO\n";
    std::cout << "    OboO\"\"\"\"\"\"\"\"\"\"\"\".OOo. .oOOOOOo.    OOOo.oOOOOOo..\"\"\"\"\"\"\"\"\"'OO\n";
    std::cout << "    OOP.oOOOOOOOOOOO \"POOOOOOOOOOOo.   `\"OOOOOOOOOP,OOOOOOOOOOOB'\n";
    std::cout << "    `O'OOOO'     `OOOOo\"OOOOOOOOOOO` .adOOOOOOOOO\"oOOO'    `OOOOo\n";
    std::cout << "    .OOOO'            `OOOOOOOOOOOOOOOOOOOOOOOOOO'            `OO\n";
    std::cout << "    OOOOO                 '\"OOOOOOOOOOOOOOOO\"`                oOO\n";
    std::cout << "   oOOOOOba.                .adOOOOOOOOOOba               .adOOOOo.\n";
    std::cout << "  oOOOOOOOOOOOOOba.    .adOOOOOOOOOO@^OOOOOOOba.     .adOOOOOOOOOOOO\n";
    std::cout << " OOOOOOOOOOOOOOOOO.OOOOOOOOOOOOOO\"`  '\"OOOOOOOOOOOOO.OOOOOOOOOOOOOO\n";
    std::cout << " \"OOOO\"       \"YOoOOOOMOIONODOO\"`  .   '\"OOROAOPOEOOOoOY\"     \"OOO\"\n";
    std::cout << "    Y           'OOOOOOOOOOOOOO: .oOOo. :OOOOOOOOOOO?'         :`\n";
    std::cout << "    :            .oO\%OOOOOOOOOOo.OOOOOO.oOOOOOOOOOOOO?         .\n";
    std::cout << "    .            oOOP\"\%OOOOOOOOoOOOOOOO?oOOOOO?OOOO\"OOo\n";
    std::cout << "                 '\%o  OOOO\"\%OOOO\%\"\%OOOOO\"OOOOOO\"OOO':\n";
    std::cout << "                      `$\"  `OOOO' `O\"Y ' `OOOO'  o             .\n";
    std::cout << "    .                  .     OP\"          : o     .\n";
    std::cout << "                              :\n";
    std::cout << "                              .\n\n\n";

    return 0; 
}

bool PlayGame(int Difficulty)
{
    // use seed rand() using time (from ctime)
    srand(time(NULL));
    // then take the remainder of rand / difficulty + difficulty
    // to produce a random range
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    CurrentGuess++;

    // InitialiseVariables
    std::cout << "This is a level " << Difficulty << " secure room\n";
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The numbers add up to " << CodeSum << std::endl;
    std::cout << "The numbers multiply to " << CodeProduct << std::endl;

    InputPlayerGuess();

    if  (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n>>> Congratulations! You got it right! <<<\n\n";

        return true;
    }
    else
    {
        std::cout << "\n>>> That wasn't it! <<<\n\n";
        const int GuessesRemaining = TotalGuesses - CurrentGuess;
        std::cout << "There are " << GuessesRemaining << " attempts left! ";

        return false;
    }
}

// output a static intro
void OutputIntro()
{
    std::cout << "                      :::!~!!!!!:.\n";
    std::cout << "                  .xUHWH!! !!?M88WHX:.\n";
    std::cout << "                .X*#M@$!!  !X!M$$$$$$WWx:.\n";
    std::cout << "               :!!!!!!?H! :!$!$$$$$$$$$$8X:\n";
    std::cout << "              !!~  ~:~!! :~!$!#$$$$$$$$$$8X:\n";
    std::cout << "             :!~::!H!<   ~.U$X!?R$$$$$$$$MM!\n";
    std::cout << "             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM!\n";
    std::cout << "               !:~~~ .:!M\"T#$$$$WX??#MRRMMM!\n";
    std::cout << "               ~?WuxiW*`   `\"#$$$$8!!!!??!!!\n";
    std::cout << "             :X- M$$$$       `\"T#$T~!8$WUXU~\n";
    std::cout << "            :\%`  ~#$$$m:        ~!~ ?$$$$$$\n";
    std::cout << "          :!`.-   ~T$$$$8xx.  .xWW- ~\"\"##*\"\n";
    std::cout << ".....   -~~:<` !    ~?T#$$@@W@*?$$      /`\n";
    std::cout << "W$@@M!!! .!~~ !!     .:XUW$W!~ `\"~:    :\n";
    std::cout << "#\"~~`.:x\%`!!  !H:   !WM$$$$Ti.: .!WUn+!`\n";
    std::cout << ":::~:!!`:X~ .: ?H.!u \"$$$B$$$!W:U!T$$M~\n";
    std::cout << ".~~   :X@!.-~   ?@WTWo(\"*$$$W$TH$! `\n";
    std::cout << "Wi.~!X$?!-~    : ?$$$B$Wu(\"**$RM!\n";
    std::cout << "$R@i.~~ !     :   ~$$$$$B$$en:``\n";
    std::cout << "?MXT@Wx.~    :     ~\"##*$$$$M~\n\n";

    std::cout << "Only one more step to go!\n\n";
    std::cout << "You've avoided all the booby traps and security ";
    std::cout << "so there's just one more thing to do - ";
    std::cout << "hack the terminal!\n";
    std::cout << "It's all down to you!\n\n";
}

// get player input
void InputPlayerGuess()
{
    std::cout << "Enter your 3 numbers\n";
    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "You entered " << GuessA << ", " << GuessB << ", " << GuessC << std::endl;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "The numbers add up to " << GuessSum << std::endl;
    std::cout << "The numbers multiply to " << GuessProduct << std::endl;
}

// resolve errors in the input stream
void ResetStdIn()
{
    // clear and std in errors
    std::cin.clear();
    // discard the buffer
    std::cin.ignore();
}
