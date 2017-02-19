#include "../headers.h"

using namespace std ;

Parser::Parser()
{

}

vector<string> Parser::Parse_Words( string text )
{
    int length = text.length() ;
    vector<int> emptySpacePositions ;
    vector<string> vectorOfWords ;

    //cout << "Space positions:\n" ;
    emptySpacePositions.push_back(-1) ;
    //cout << -1 << endl ;


    for( int i = 0 ; i<length ; i++ )
    {
        if ( text[i] == ' ' )
        {
            emptySpacePositions.push_back(i) ;
            //cout << i << endl ;
        }
    }

    emptySpacePositions.push_back(length) ;
    //cout << length << endl ;

    int numberOfSpaces = emptySpacePositions.size()  ;

    for( int i = 0 ; i<numberOfSpaces-1 ; i++ )
    {
        if ( emptySpacePositions[i+1] - emptySpacePositions[i] > 1 )
        {
            int newWordLength = emptySpacePositions[i+1] - emptySpacePositions[i] ;
            string newWord = text.substr(emptySpacePositions[i]+1,newWordLength-1);

            vectorOfWords.push_back(newWord);
        }
    }

    return vectorOfWords ;
}


Command* Parser::Parse_Sentence( vector<string> words )
{
    string action = "",
           tool = "",
           preposition = "",
           target = "" ;

    bool prepositionExists = false ;
    vector<string>::iterator prepIt = words.begin() ;

    if( words.size() > 0 ) action = words[0] ;

    if ( words.size() == 2 )
    {
        target = words[1] ;
    }
    else if( words.size() > 2 )
    {
        for ( vector<string>::iterator it = words.begin()+1 ; it != words.end() ; ++it ) // check for ++it
        {
            if( *it == "on" && !prepositionExists)
            {
                prepIt = it ;
                preposition = *prepIt ;

                prepositionExists = true ;

                it++ ;
            }

            if (!prepositionExists)
            {
                tool += *it ;
                tool += ' ' ;
            }
            else
            {
                target += *it ;
                target += ' ' ;
            }
        }

        // remove the last (empty) space from each string
        tool = tool.substr(0,tool.length()-1) ;
        target = target.substr(0,target.length()-1) ;

    }

    if( tool != "" && preposition == "" && target == "" )
    {
        target = tool ;
        tool = "" ;
    }

    //cout << action << "_" << tool << "_" << preposition << "_" << target << ".\n" ;
    Command* command = new Command(action,tool,preposition,target) ;

    return command ;
}
