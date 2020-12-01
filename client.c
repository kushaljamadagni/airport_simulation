#include"server.h"
void main( )
{
    struct airport a ;
    int i, pri, curtime, endtime ;
    double expectarrive, expectdepart ;
    struct plane temp ;
    initairport ( &a );
    start ( &endtime, &expectarrive, &expectdepart ) ;

    for ( curtime = 1 ; curtime <= endtime ; curtime++ )
    {

        for ( i = 1 ; i <= 1; i++ )
        {
        newplane ( &a, curtime, ARRIVE ) ;
            if ( aipfull ( a, 'l' ) )
                 refuse ( &a, ARRIVE ) ;
            else
                aipaddqueue( &a, 'l' );

        }
        for ( i = 1 ; i <= 1 ; i++ )
        {

         newplane ( &a, curtime, DEPART ) ;
            if ( aipfull ( a, 't' ) )
               refuse ( &a, DEPART ) ;
            else
               aipaddqueue ( &a, 't' ) ;
        }
    if (  ! ( aipempty ( a, 'l' )) )
      {

          temp = aipdelqueue ( &a, 'l' ) ;
            land ( &a, temp, curtime ) ;
        }
    else if ( ! ( aipempty ( a, 't' )) )

    {

                temp = aipdelqueue ( &a, 't' ) ;
                fly ( &a, temp, curtime ) ;
    }
    else
        {
                idle ( &a, curtime ) ;
        }






    }