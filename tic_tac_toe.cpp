
#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstdbool>

using  namespace std ;

bool condition( char Gboard[ ][3] , bool winner,char*player01 , char*player02)
{
    int line , row ;

    for( line = 0 ; line < 3 ; line++)
    {
        if( (Gboard[line][0] == Gboard[line][1]) && (Gboard[line][0] == Gboard[line][2]) )

        if(Gboard[line][0] == 'X')
        {
            cout << player01 << " won " ;
            winner = true ;
        }

        else if( Gboard[line][0] == 'O')
        {
            cout << player02 << " won " ;
            winner = true ;
        }
    }

    for( row = 0 ; row < 3 ; row++)
    {
        if((Gboard[0][row] == Gboard[1][row]) && (Gboard[0][row] == Gboard[2][row]))

        if(Gboard[0][row] == 'X')
        {
            cout << player01 << " won " ;
            winner = true ;
        }

        else if( Gboard[0][row] == 'O')
        {
            cout << player02 << " won " ;
            winner = true ;
        }
    }

    if( (Gboard[0][0] == Gboard[1][1]) && (Gboard[0][0] == Gboard[2][2]))
    {
        if(Gboard[0][0] == 'X')
        {
            cout << player01 << " won " ;
            winner = true ;
        }

        else if( Gboard[0][0] == 'O')
        {
            cout << player02 << " won " ;
            winner = true ;
        }
    }

    else if(  (Gboard[2][2] == Gboard[1][1]) && (Gboard[2][2] == Gboard[2][0]) )
    {
        if(Gboard[2][2] == 'X')
        {
            cout << player01 << " won " ;
            winner = true ;
        }

        else if( Gboard[2][2] == 'O')
        {
            cout << player02 << " won " ;
            winner = true ;
        }
    }

    return winner ;
}

bool print_the_board( int * board , bool winner,char*player01 , char*player02 )
{
    char Gboard[3][3] ;

    //reset the board 

    for( int i = 0 ; i < 3 ; i++)
    {
        for( int j = 0 ; j < 3 ; j++)
        {
            Gboard[i][j] = ' ' ;
        }
    }

    int X = 0 , O = 1;
 	
 	
 	//Printing all
 	
 	while( X < 9)
 	{
 		if( board[X] == 1 )
 		{	
 			Gboard[0][0] = 'X';
 		}
 		
 		else if( board[O] == 1)
 		{
 			Gboard[0][0] = 'O';	
 		}
 		
 		 if( board[X] == 2 )
 		{
 			Gboard[0][1] = 'X';		
 		}
 		
 		else if( board[O] == 2)
 		{
 			Gboard[0][1] = 'O';
 		}
 		
 		if( board[X] == 3 )
 		{
            Gboard[2][2] = 'X';
 		}
 		
 		else if( board[O] == 3)
 		{
 			Gboard[0][2] = 'O';	
 		}
 			
 		if( board[X] == 4 )
 		{
 			Gboard[1][0] = 'X';	
 		}
 		
 		else if( board[O] == 4)
 		{
 			Gboard[1][0] = 'O';	
 		}
 		
 		if( board[X] == 5 )
 		{
 			Gboard[1][1] = 'X';	
 		}
 		
 		else if( board[O] == 5)
 		{
 			Gboard[1][1] = 'O';	
 		}
 		
 		 if( board[X] == 6 )
 		{
 			Gboard[1][2] = 'X';	
 		}
 		
 		else if( board[O] == 6)
 		{
 			Gboard[1][2] = 'O';		
 		}

 		if( board[X] == 7 )
 		{
 			Gboard[2][0] = 'X';
 		}
 		
 		else if( board[O] == 7)
 		{
 			Gboard[2][0] = 'O';
 		}
 		
 		if( board[X] == 8 )
 		{
 			Gboard[2][1] = 'X';		
 		}
 		
 		else if( board[O] == 8)
 		{
 			Gboard[2][1] = 'O';	
 		}
 		
 	    if( board[X] == 9 )
 		{
 			Gboard[2][2] = 'X';
 		}
 		
 		else if( board[O] == 9)
 		{
 			Gboard[2][2] = 'O';
 		}
 		
 		X += 2 ;
 		
 		O += 2 ;
 	
 	}

    cout << "| "<< Gboard[0][0] << " | " << Gboard[0][1] << " | " << Gboard[0][2] << " |" << endl ;
    cout << "| "<< Gboard[1][0] << " | " << Gboard[1][1] << " | " << Gboard[1][2] << " |" << endl ;
    cout << "| "<< Gboard[2][0] << " | " << Gboard[2][1] << " | " << Gboard[2][2] << " |" << endl << endl ;

    winner = condition( Gboard , winner , player01 , player02) ;

    return winner ;
}

void input(char*player01 , char*player02 , bool winner )
{
    int board[9] ;

    int index = 0 , indice = 1  , turn = 1 ;

    while( ( turn <= 5 ) || ( winner = true ))
    {
        cout << player01 <<" your turn ( choice "<<turn<<" ) : " ;
        cin >> board[index] ;

        while ( board[index] == board[indice])
        {
            cout << " the previous player already choosed this number , please  choose a other one "<<endl<<endl ;
            cout << player01 <<" your turn ( choice "<<turn<<" ) : " ;
            cin >> board[index] ;
        }

        printf("\n\n") ;

        winner = print_the_board( board , winner , player01 , player02) ;

        if( turn == 5)
        {
            cout << "Turn's up" ;
            break ;
        }

        else
        {
            
            cout << player01 <<" your turn ( choice "<<turn<<" ) : " ;
            cin >> board[index] ;

            while ( board[index] == board[indice])
            {
                cout << " the previous player already choosed this number , please  choose a other one "<<endl<<endl ;
                cout << player02 <<" your turn ( choice "<<turn<<" ) : " ;
                cin >> board[index] ;
            }

            printf("\n\n") ;

            winner = print_the_board( board , winner , player01 , player02) ;
        }

        turn++ ; index = index + 2 ; indice = indice + 2 ;       

        printf("\n\n") ;
    }
}

int main (void)
{
    char player01[30] , player02[30] ;

    bool winner = false ;

    cout << "player 01 your name : " ;
    cin >> player01 ;

    cout << "player 02 your name : " ;
    cin >> player02 ;

    input(player01 , player02 , winner ) ;
}
