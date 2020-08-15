/*
      RoboCore - Tutorial Comunicacao entre Arduinos: SPI - (micro)
                                                        (30/05/2015)
*/

#include "SPI.h"
#include <communicationSPI.h>
Check Check; 
micro micro; 

#include <ReadMaxIII.h>
#include <boards/microSENSORS.h>
Read Read; 


void setup() {


   Serial.begin(115200);
   
   micro.begin();   
   Check.begin(); 
}

void loop() {


//============================================================================================================================================
                                                           //CONDITION 10 
//============================================================================================================================================
        while(Check.condition_line() == true)  // verification ramp and obstacle 
         {


          if(analogRead(A7) > 500)
          {
             micro.transfer(10); 
          }
          else
          {
             micro.transfer(11); 
          }
           
         } 
//============================================================================================================================================
                                                           //CONDITION 2
//============================================================================================================================================
         while(Check.condition_rightObstacle() == true)  // verification only SHARPS ramp 
         {
          micro.transfer(2); 
           
         } 
//============================================================================================================================================
                                                           //CONDITION 3 
//============================================================================================================================================
           while(Check.condition_leftObstacle() == true) // verification only SHARP tri right 
         {
          
           micro.transfer(3); 
           
         } 
         
//============================================================================================================================================
                                                           //CONDITION 4
//============================================================================================================================================       
           while(Check.condition_ramp() == true)  // verification only SHARP tri left
         {
          
           micro.transfer(4); 

         } 
//============================================================================================================================================
                                                           //CONDITION 5
//============================================================================================================================================
          while(Check.condition_triRight() == true)  // verification only SHARPS UP and DOWN Right 
         {
          
           micro.transfer(5); 
           
         }
//============================================================================================================================================
                                                           //CONDITION 6
//============================================================================================================================================
          while(Check.condition_triLeft() == true)    // verification only SHARPS UP and DOWN Left
         {
          
           micro.transfer(6); 
           
         } 
//============================================================================================================================================
                                                           //CONDITION 7
//============================================================================================================================================
          while(Check.condition_searchingOnlyRight() == true)    //verification only SHARPS UP and Down Left and Right 
         {
          
           micro.transfer(7); 
           
         } 
//============================================================================================================================================
                                                           //CONDITION 8
//============================================================================================================================================
          while(Check.condition_searchingOnlyLeft() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(8); 
           
         } 

          while(Check.condition_searchingLeftAndRight() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(9); 
           
         } 

         while(Check.condition_front() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(10); 
           
         } 

         while(Check.condition_rear() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(11); 
           
         } 

         while(Check.condition_frontAndRear() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(12); 
           
         } 

         while(Check.condition_13() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(13); 
           
         } 

         while(Check.condition_14() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(14); 
           
         } 

         while(Check.condition_15() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(15); 
           
         } 

         while(Check.condition_16() == true)   // Verification only SHARPS Front and Back 
         {
          
           micro.transfer(16); 
           
         } 
}









