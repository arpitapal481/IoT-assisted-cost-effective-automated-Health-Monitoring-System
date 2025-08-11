// Print Database function
void printDB(int db[][4], int start, int end ) {
   for ( int i = start; i < end; ++i ) { 
     for ( int j = 0; j < 4; ++j ){ 
      Serial.print ((float)db[ i ][ j ]/10 );
      Serial.print (" ") ;
     }
   Serial.println();
   }
}
