#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

//Bunun meqsedi boardi temizlemekdi
void ResetBoard(){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}

//Boardi matris sekilde cixardim
void PrintBoard(){
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n------------\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n------------\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);

} //Demeli burada loopun meqsedi odu ki bize bos yer qal;b qalmadigini desin
int FreeSpaces(){
    int free = 9;
    for (int i=0; i<3;i++){
        for (int j=0;j<3;j++){
            if (board[i][j]!=' '){
                free--;
            }
        }
    }
    return free;
}

void PlayerMove(){
    //Demeli men burda playere deyecem ki haraya X yazmaq isteyirse ora da yazsin
    int row;
    int col;
    do
    {
        printf("\nEnter row (1-3):\n");
        scanf("%d",&row);
        row--;
        printf("\nEnter column (1-3)\n");
        scanf("%d",&col);
        col--;
        if (board[row][col]!=' '){
            printf("\nYou cannot!\n");}
        else{
            board[row][col] = PLAYER;
            break;
        }
    } while(board[row][col]!=' ');   
}

void ComputerMove(){
    //Computer move random olmalidir
    //
    srand(time(0));
    int row;
    int col;
    char winner;
    if(FreeSpaces()>0){
        do{
            row = rand()%3;
            col = rand()%3;
        }while (board[row][col]!=' ');

        board[row][col] = COMPUTER;
    }
    else{
        PrintWinner(winner);//Burada char winner olacaq ona gore bos saxladim. O PrintWinnerin ozundeki if conditionunda mueyyenlesecek.  
    }
}

    
char CheckWinner(){
    // burda boardin diaqonalini, sutununu, bir de sirasini yoxlamaliyam ki udub udmadigini bilim
    //Sirani yoxlamaq
    for (int i = 0; i < 3; i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]==board[i][2]){
        
        return board[i][0];//Zaten hansisa birini cixarsin yeni X dirse X qaytarsin o da winner sayilacaq.
    }}
    //Sutunu yoxlamaq
    for (int j=0;j<3;j++){
        if (board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[0][j]==board[2][j]){
            return board[0][j];
        }
        }
    //Diagonal yoxlamaq
    if(board[0][0]==board[1][1] && board[2][2]==board[1][1] && board[0][0]==board[2][2]){
        return board[0][0];
    }
    if (board[2][0]==board[1][1] && board[1][1] == board[0][2] && board[0][2]==board[2][0]){
        return board[1][1];
    }

    return ' '; // Eger hec winner yoxdusa qaytarmasin hec ne



};
void PrintWinner(char winner){
    if (winner == PLAYER){
        printf("\nCongrats dude! You won!\n");
    }
    else if (winner == COMPUTER){
        printf("\nYou lost!\n");
    }
    else{
        printf("\nIt is tie!"); //Berabere qaldiqlari case ucun
    }
}

int main()
{
    printf("Hello dear friend! Welcome to new game project by Aysel Rahimli\n");
    printf("TIC TAC TOE GAME\nEnjoy it!\n");
    char winner = ' ';
    char response; 
    do
    {
        ResetBoard();
        while(winner==' ' && FreeSpaces()!=0){
            PrintBoard();
            PlayerMove();
            winner = CheckWinner();
            if(winner!=' ' || FreeSpaces() == 0){
                break;
            }
            ComputerMove();
            winner = CheckWinner();
            if(winner!=' ' || FreeSpaces() == 0){
                break;
            }
        }
        
        PrintBoard();
        PrintWinner(winner);  
        printf("\nDo you wanna play again? (Yes = Y / No = N):\n");
        scanf(" %c", &response);
    } while (response == 'Y' || response == 'y');

    printf("Well, thanks for playing! See you soon.\n");
    return 0;
}