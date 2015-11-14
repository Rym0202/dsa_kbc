/*****************************************************************************
 * Copyright (C) Rohit Mariwalla rymariwalla@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/* This program does not store records, but only stores "names" in hash table*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

char answ();
void lifeline();
void answe();
void generate();
int search(int);
void quit(char *);
void lost(char *);

char ans,ch;
char name[50], city[15], spend[50], quest, answer, choice, *pm;
int i, j, k, t, x, num, q, o, n, age, a, b, ctr=0, again;
char arr1[][128] = {"5,000","10,000","20,000","40,000","80,000","1,60,000","3,20,000","6,40,000","12,50,000","25,00,000","50,00,000","1,00,00,000","5,00,00,000"}; //stores the prize money
char arr2[] = {'B','A','A','C','C','D','B','B','D','A','B','A','C','C','D','C','A','A','D','B','C','C','B'};  //stores the answers
int searc[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //stores the question number already answered
static char ques[1024][132];
static char opt[1024][32];
int r = 0;
int main()
{
	while(1)
	{	
		ans = ' ';
        	t = 0; //initializing the variable t
        	q = 0; //initializing the variable q
        	n = 0; //initializing the variable n
        	o = 0; //initializing the variable o
        	i = 0; //initializing the variable i
        	j = 0; //initializing the variable j
        	num = 0; //initializing the variable num
        	age = 0; //initializing the variable age
		pm = NULL;
        

        	
		printf("-------------------------------------------\n");
        	printf("-------------------------------------------\n");
        	printf("  _     _    _     _        _ _ _ _ \n");
        	printf(" | |   / /  | |||||\\ \\   / /_ _ _ _|\n");
        	printf(" | |  / /   | |    | |  | |         \n");
        	printf(" | | / /    | |    / /  | |         \n");
        	printf(" | | \\ \\    | |||||     | |         \n");
        	printf(" | |  \\ \\   | |    \\ \\  | |         \n");
        	printf(" | |   \\ \\  | |    | |  | | _ _ _ _ \n");
        	printf(" |_|    \\_\\ |_|||||/_/   \\ \\_ _ _ _|\n");
        	printf("\n");
        	printf("-------------------------------------------\n");
        	printf("-------------------------------------------\n");
        	printf("\n");
        	printf("Welcome to Kaun Banega Crorepati\n");
        	printf("\n");	

		printf("Enter your name \n");
		char man = getchar();        
		if(man == '\n')	
		fgets(name, 50, stdin);  //stores the name
		if(name[strlen(name) - 1] == '\n')
			name[strlen(name) - 1] = '\0';   
		else
		{
			name[0] = man;
			fgets(&name[1], 50, stdin);  //stores the name
		if(name[strlen(name) - 1] == '\n')
			name[strlen(name) - 1] = '\0';   
		}
		printf("Enter your age \n"); 
        	scanf("%d", &age);  //stores the age
        	printf("Enter your city name \n");
        	scanf("%s", city);  //stores the city
        	printf("What will you do if you win 5 crore rupees?\n");
        	scanf("%s", spend);  //stores the expenditure of the canditate
        	printf("\n");
	
	
		printf("Rules=>\n\n\n");
        	printf("You have to answer 13 questions. There are two safe marks which are at Rs.10,000 and Rs.3,20,000\n\n");
        	printf("which if you win, you will atleast take away Rs.10,000 or Rs.3,20,000 respectively from here.\n\n");
        	printf("There are 3 lifelines=> Audience Poll, Double Dip, Ask the experts and you can leave \n\n");
        	printf("the game at any question.\n\n");
        	printf("During game press 'L' to use a lifeline and 'Q' to quit the game.\n\n");
        	printf("Answer every question in capital letters ONLY.\n\n");
        	printf("Please do not enter an empty or null answer\n\n");
        	printf("\n\n");
        	printf("Now let us start Kaun Banega Crorepati with %s\n\n", name);
	
		FILE *fp = fopen("questions.txt", "r");
		while(fgets(ques[q], 1024, fp))//loop reads a line from text file and stores it in an array 
		{
			q++;
			if(ques[q][strlen(ques[q]) - 1] == '\n')
			ques[q][strlen(ques[q]) - 1] = '\0';
		}
		fclose(fp);
	
		fp = fopen("options.txt", "r");
		while(fgets(opt[o], 1024, fp))//loop reads a line from text file and stores it in an array
		{
			o++;
			if(opt[o][strlen(ques[o]) - 1] == '\n')
			opt[o][strlen(ques[o]) - 1] = '\0';
		}	
		fclose(fp);
	
		for(i = 0; i < 13; i++) // asks 13 questions
        	{
        	    	if(i == 0)
        	    	{
        	        	printf("\nQuestion %d for Rs.%s is=>", i + 1, arr1[i]);
        	    	}
        	    	else
        	    	{
        	        	printf("\nNext question is for Rs.%s. The question is=>", arr1[i]);
        	    	}
        	    	generate();
        	    	printf("\n%s", ques[num]);  //prints the question
        	    	printf("\n");
        	    	for(j = num * 4; j < ((num * 4) + 4); j++)
        	    	{
        	        	printf("\n%s", opt[j]); //prints the 4 options
        	    	}
        	    	ans = answ();
		  
        	        printf("\n");
			printf("\n");
        	        if(ans == arr2[num]) // prints these lines if the answer is right
        	        {                
        	        	if(i == 1 || i == 6)
        	        	{
					printf("\n");
        	        		printf(" %c is the correct answer. Congratulations!!!", arr2[num]);
				        printf("You have won Rs.%s", arr1[i]);
        	        	        printf("\nCongratulations now you will at least take Rs.%s from here", arr1[i]);
        	         	}
        	        	else if(i == 0 || (i <= 5 && i > 1))
        	        	{
					printf("\n");
        	            		printf(" %c is the correct answer. ", arr2[num]);
					printf("Congratulations!!! You have won Rs.%s", arr1[i]);
        	        	}
        	        	else if(i >= 7 && i <= 11)
        	        	{
					printf("\n");
        	            		printf(" %c is the correct answer. ", arr2[num]);
					printf("Congratulations!!! You have won Rs.%s", arr1[i]);
        	            		printf("\n%s, you are playing very well. You are only %d questions away from winning Rs.5 crores.", name, 12-i);
        	        	}
        	        	else
        	        	{
					printf("\n");
        	            		printf(" %c is the correct answer. ", arr2[num]);
					printf("Congratulations!!! You have won Rs.%s", arr1[i]);
        	            		printf("\nYou have played fantastic and now you can fulfill your dreams with this huge amount of Rs.%s", arr1[i]);
        	        	}
        	        	pm = arr1[i];  //stores the prize money
        	    	}
        	    	else
        	    	if(ans == 'L' || ans == 'l')
        	    	{
        	        	lifeline();  //calls the lifeline function
        	    	}
        	    	else
        	    	if(ans == 'Q' || ans == 'q')
        	    	{
        	        	quit(pm); //calls the quit function
        	    	}
        	    	else //if the answer is wrong
        	    	{
        	        	printf("\nSorry!!! This is the wrong answer. The correct answer is %c", arr2[num]);
        	        	lost(pm);
        	    	}
		}  
		printf("\n");
        	printf("\nPress '1' to play again...."); //if the contestant wants to play again
        	printf("\nPress any other key to exit....");
        	scanf("%d", &again);
		//printf("%d", again);        
		if(again == 1)
        	{
        		; //if the contestant plays again      
		r++;	
		}
        	else
        	{    
        		exit(1000); //if the contestant does not want to play again//doubt
        	}
        }
	return 0;
}

char answ()//stores answer by the contestant
{	
	while(1)
	{
       		printf("Enter your answer=> ");
       		scanf(" %c", &answer);//stores the answers
       		answer = toupper(answer);
		ans = answer;
       		if( (ans != 'A') && (ans != 'B') && (ans != 'C') && (ans != 'D') && (ans != 'Q') && (ans != 'L'))
       			printf("\nInvalid Input. Enter the answer again.");
       		else
			break;
       	}
       	return ans;
}


void lifeline()//for the lifeline by the contestant
{
        if(t == 0)
        {
        	printf("\n");
                printf("\nYou have 3 lifelines=>");
                printf("\nA.Audience Poll");
                printf("\nB.Double Dip");
                printf("\nC.Ask The Experts");
                printf("Enter your choice=> ");
                scanf("%s", &choice);//stores the lifeline choice
                choice=toupper(choice);
                ch=choice;
        }
       	else
       	if(t == 2)
       	{
       	        printf("\n");
                printf("\nYou have already used the Audience poll lifeline.");
                printf("\n");
                printf("\nYou have 2 lifelines left=>");
                printf("\nB.Double Dip");
                printf("\nC.Ask The Experts");
                printf("Enter your choice=> ");
	        scanf("%s", &choice);//stores the lifeline choice
                choice=toupper(choice);
                ch=choice;
                if(ch == 'A') //if the lifeline is already used
                {
        	        lifeline();
        	        ch = 'U';
          	}
        }
       	else
        if(t == 3)
        {
                printf("\n");
                printf("\nYou have already used the Double Dip lifeline.");
                printf("\n");
                printf("\nYou have 2 lifelines left=>");
                printf("\nA.Audience Poll");
                printf("\nC.Ask The Experts");
                printf("Enter your choice=> ");
	        scanf("%s", &choice);//stores the lifeline choice
                choice=toupper(choice);
                ch=choice;
                if(ch == 'B') //if the lifeline is already used
                {
        	        lifeline();
        	        ch = 'U';
        	}
        }
        else
        if(t == 4)
        {
        	printf("\n");
                printf("\nYou have already used the Ask the experts lifeline.");
                printf("\n");
                printf("\nYou have 2 lifelines left=>");
                printf("\nA.Audience Poll");
                printf("\nB.Double Dip");
                printf("\nEnter your choice=> ");
	        scanf("%s", &choice);//stores the lifeline choice
                choice=toupper(choice);
                ch=choice;
                if(ch == 'C') //if the lifeline is already used
                {
        	        lifeline();
        	        ch = 'U';
        	}
        }
        else
        if(t == 5)
        {
        	printf("\n");
                printf("\nYou have already used the Audience poll and Double Dip lifeline.");
                printf("\n");
                printf("\nYou have 1 lifeline left=> ");
                printf("\nC.Ask The Experts");
                printf("Enter your choice=>");
	        scanf("%s", &choice);//stores the lifeline choice
                choice=toupper(choice);
                ch=choice;
                if(ch == 'A' || ch == 'B') //if the lifeline is already used
                {
        	        lifeline();
        	        ch = 'U';
        	}
        }
       	else
        if(t == 7)
        {
        	printf("\n");
                printf("\nYou have already used the Double Dip and Ask the experts lifeline.");
                printf("\n");
                printf("\nYou have 1 lifeline left=> ");
                printf("\nA.Audience Poll");
                printf("Enter your choice=>");
	        scanf("%s", &choice);//stores the lifeline choice
                choice=toupper(choice);
                ch=choice;
                if(ch == 'B' || ch == 'C') //if the lifeline is already used
                {
        	        lifeline();
        	        ch = 'U';
        	}
        }
        else
        if(t == 6)
        {
        	printf("\n");
                printf("\nYou have already used the Audience poll and Ask the experts lifeline.");
                printf("\n");
                printf("\nYou have 1 lifeline left=> ");
                printf("\nB.Double Dip");
                printf("Enter your choice=>");
                scanf("%s", &choice);//stores the lifeline choice
                choice=toupper(choice);
                ch=choice;
                if(ch == 'A' || ch == 'C') //if the lifeline is already used
                {
        	        lifeline();
        	        ch = 'U';
        	}
        }
        else
        {
        	printf("\nSorry!!! All your lifelines are used.");
                printf("\nYou have no life lines left.");
                ch = 'D';
        }
		
	switch(ch)
        {
            	case 'U':
            	{
               		break;
            	}
            	case 'A': //if Audience Poll lifeline is used
            	{
                	t = t + 2;
                	printf("\n");
                	printf("\nYou have chosen Audience Poll.");
                	if(num == 0)
                	{
                		printf("\nAccording to the audience=>");
                		printf("\nA:20%%");
                	 	printf("\nB:70%%");
                	 	printf("\nC:5%%");
                	 	printf("\nD:5%%");
                	}
                	else
                	if(num == 1)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:90%%");
                	    	printf("\nB:1%%");
                	    	printf("\nC:9%%");
                	    	printf("\nD:0%%");
                	}
                	else
                	if(num == 2)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:80%%");
                	    	printf("\nB:20%%");
                	    	printf("\nC:0%%");
                	    	printf("\nD:0%%");
                	}
                	else
                	if(num == 3)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:30%%");
                	    	printf("\nB:10%%");
                	    	printf("\nC:50%%");
                	    	printf("\nD:10%%");
                	}
                	else
                	if(num == 4)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:30%%");
                	    	printf("\nB:10%%");
                	    	printf("\nC:50%%");
                	    	printf("\nD:10%%");
                	}
                	else
                	if(num == 5)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:40%%");
                	    	printf("\nB:5%%");
                	    	printf("\nC:10%%");
                	    	printf("\nD:45%%");
                	}
                	else
                	if(num == 6)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:40%%");
                	    	printf("\nB:47%%");
                	    	printf("\nC:10%%");
                	    	printf("\nD:3%%");
                	}
                	else
                	if(num == 7)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:33%%");
                	    	printf("\nB:33%%");
                	    	printf("\nC:30%%");
                	    	printf("\nD:4%%");
                	}
                	else
                	if(num == 8)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:35%%");
                	    	printf("\nB:20%%");
                	    	printf("\nC:15%%");
                	    	printf("\nD:30%%");
                	}
                	else
                	if(num == 9)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:40%%");
                	    	printf("\nB:30%%");
                	    	printf("\nC:10%%");
                	    	printf("\nD:20%%");
                	}
                	else
                	if(num == 10)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:10%%");
                	    	printf("\nB:50%%");
                	    	printf("\nC:30%%");
                	    	printf("\nD:10%%");
                	}
                	else
                	if(num == 11)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:30%%");
                	    	printf("\nB:30%%");
                	    	printf("\nC:25%%");
                	    	printf("\nD:15%%");
                	}
                	else
                	if(num == 12)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:20%%");
                	    	printf("\nB:10%%");
                	    	printf("\nC:45%%");
                	    	printf("\nD:25%%");
                	}
                	else
                	if(num == 13)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:5%%");
                	    	printf("\nB:10%%");
                	    	printf("\nC:80%%");
                	    	printf("\nD:5%%");
                	}
                	else
                	if(num == 14)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:20%%");
                	    	printf("\nB:10%%");
                	    	printf("\nC:10%%");
                	    	printf("\nD:60%%");
                	}
                	else
                	if(num == 15)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:20%%");
                	    	printf("\nB:10%%");
                	    	printf("\nC:45%%");
                	    	printf("\nD:25%%");
                	}
                	else
                	if(num == 16)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:40%%");
                	    	printf("\nB:30%%");
                	    	printf("\nC:20%%");
                	    	printf("\nD:10%%");
                	}
                	else
                	if(num == 17)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:60%%");
                	    	printf("\nB:20%%");
                	    	printf("\nC:10%%");
                	    	printf("\nD:10%%");
                	}
                	else
                	if(num == 18)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:25%%");
                	    	printf("\nB:25%%");
                	    	printf("\nC:20%%");
                	    	printf("\nD:30%%");
                	}
                	else
                	if(num == 19)
                	{
                	 	printf("\nAccording to the audience=>");
                	    	printf("\nA:25%%");
                	    	printf("\nB:30%%");
                	    	printf("\nC:30%%");
                	    	printf("\nD:25%%");
                	}
                	else
                	if(num == 20)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:5%%");
                	    	printf("\nB:25%%");
                	    	printf("\nC:40%%");
                	    	printf("\nD:30%%");
                	}
                	else
                	if(num == 21)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:15%%");
                	    	printf("\nB:30%%");
                	    	printf("\nC:31%%");
                	    	printf("\nD:24%%");
                	}
                	else
                	if(num == 22)
                	{
                	    	printf("\nAccording to the audience=>");
                	    	printf("\nA:10%%");
                	    	printf("\nB:40%%");
                	    	printf("\nC:35%%");
                	    	printf("\nD:15%%");
                	}
                	answe(); //goes directly to the answer function
                	break;
		}
		case 'B': //if Double Dip lifeline is used
                {
                	ans=' ';
                	printf("\n");
                	t = t + 3;
                	printf("\nYou have chosen Double Dip.");
                	printf("\nYou cannot quit now.");
                	printf("\n");
                	printf("Enter your 1st answer=> ");
                	scanf(" %c", &answer);//stores the answers
                	answer=toupper(answer);
                	ans=answer;
                
                	if(i == 12)
                	{
                    		for(a = 1; a <= 10; a++)
                    		{
                        		printf("*");
                    		}
                	}
                	else
                	{
                    		for(a = 1; a <= 5; a++)
                    		{
                        		printf("*");
                    		}
                	}
                
                	printf("\n");
                	if(ans == arr2[num]) //if the answer is right on the first attempt 
                	{
                    		printf(" %c is the correct answer. Congratulations!!! You have won Rs.%s", arr2[num], arr1[i]);
                    		pm=arr1[i];
                	}
                	else //if the answer is wrong at the first attempt
                	{
                    		printf("\nThis is the wrong answer.");
                    		printf("\n");
                    		printf("Enter your 2nd answer=> ");
				scanf(" %c", &answer);//stores the answers
                		answer = toupper(answer);
                		ans = answer;
                    		if(ans == arr2[num]) //if the answer is right on the second attempt 
                    		{
                        		printf(" %c is the correct answer. Congratulations!!! You have won Rs.%s", arr2[num], arr1[i]);
                        		pm=arr1[i];
                    		}
                    		else //if the answer is wrong on the second attempt
                    		{
                        		printf("\nSorry!!! This is the wrong answer. The correct answer is %c", arr2[num]);
                        		lost(pm);
                    		}
                	}
                	break;
            	}
		case 'C': //if Ask the Experts lifeline is used
            	{
                	t = t + 4;
                	printf("\nYou have choosen Ask the experts.");
                	printf("\n");
                	if(num == 0)
                	{
                	    printf("\nAccording to our experts the correct answer is B.");
                	}
                	else
                	if(num == 1)
                	{
                	    printf("\nAccording to our experts the correct answer is A.");
                	}
                	else
                	if(num == 2)
                	{
                	    printf("\nAccording to our experts the correct answer is A.");
                	}
                	else
                	if(num == 3)
                	{
                	    printf("\nAccording to our experts the correct answer is C.");
                	}
                	else
                	if(num == 4)
                	{
                	    printf("\nAccording to our experts the correct answer is C.");
                	}
                	else
                	if(num == 5)
                	{
                	    printf("\nAccording to our experts the correct answer is D.");
                	}
                	else
                	if(num == 6)
                	{
                	    printf("\nAccording to our experts the correct answer is A or B.");
                	}
                	else
                	if(num == 7)
                	{
                	    printf("\nAccording to our experts the correct answer is B or C.");
                	}
                	else
                	if(num == 8)
                	{
                	    printf("\nAccording to our experts the correct answer is A or D.");
                	}
                	else
                	if(num == 9)
                	{
                	    printf("\nAccording to our experts the correct answer is A.");
                	}
                	else
                	if(num == 10)
                	{
                	    printf("\nAccording to our experts the correct answer is B or C.");
                	}
                	else
                	if(num == 11)
                	{
                	    printf("\nAccording to our experts the correct answer is A or B.");
                	}
                	else
                	if(num == 12)
                	{
                	    printf("\nAccording to our experts the correct answer is C.");
                	}
                	else
                	if(num == 13)
                	{
                	    printf("\nAccording to our experts the correct answer is C.");
                	}
                	else
                	if(num == 14)
                	{
                	    printf("\nAccording to our experts the correct answer is B or D.");
                	}
                	else
                	if(num == 15)
                	{
                	    printf("\nAccording to our experts the correct answer is C.");
                	}
                	else
                	if(num == 16)
                	{
                	    printf("\nAccording to our experts the correct answer is A.");
                	}
                	else
                	if(num == 17)
                	{
                	    printf("\nAccording to our experts the correct answer is A.");
                	}
                	else
                	if(num == 18)
                	{
                	    printf("\nAccording to our experts the correct answer is C or D.");
                	}
                	else
                	if(num == 19)
                	{
                	    printf("\nAccording to our experts the correct answer is B or D.");
                	}
                	else
                	if(num == 20)
                	{
                	    printf("\nAccording to our experts the correct answer is B or C.");
                	}
                	else
                	if(num == 21)
                	{
                	    printf("\nAccording to our experts the correct answer is C.");
                	}
                	else
                	if(num == 22)
                	{
                	    printf("\nAccording to our experts the correct answer is B.");
                	}
                	answe();
                	break;
            	}	
		
		case 'D': //if all the lifelines are used
	        {
	                t = t+1;
	                answe();
	                break;
	        }
	        default:
	        {
	                printf("\n");
	                printf("\nInvalid option. Enter again.");
	                lifeline();
	                break;
	        }

	}
}

void answe()//the answer entered by the contestant using the lifeline
{
	if(t <= 9)
	{
        	if(ch == 'A')
	        {
	        	printf("\n");
	        }
	        else
	        if(ch == 'C')
	        {
	                printf("\n");
	        }
	        else
	        {
	                printf("\n");
	        }
		scanf(" %c", &answer);//stores the answers
                answer = toupper(answer);
                ans = answer;
	        printf("Enter your answer=>");
	 }
	 else
	 if(t > 9)
	 {
	        printf("\n");
	        printf("%s", ques[num]);  //prints the question again
	        printf("\n");
	        for(j = num*4; j < ((num*4)+4); j++)
	        {
	        	printf("%s", opt[j]); //prints the 4 options again
	        }
	        printf("Enter your answer=>");
		scanf(" %c", &answer);//stores the answers
                answer = toupper(answer);
                ans = answer;
	 }
	 if(i == 12)
	 {
	        for(a = 1; a <= 10; a++)
	         {
	                printf("*");
	         }
	 }
	 else
	 {
	         for(a = 1; a <= 5; a++)
	         {
                	printf("*");
            	 }	
         }
        
         if(ans == arr2[num]) //if the answer is right
         {

            	 printf("\n");
            	 if(i == 1 || i == 6)
            	 {
                 	printf(" %c is the correct answer. Congratulations!!! You have won Rs.%s", arr2[num], arr1[i]);
                 	printf("\nCongratulations now you will at least take Rs.%s from here.", arr1[i]);
            	 }
            	 else
            	 if(i == 0 || (i <= 5 && i > 1))
               	 {
                	printf(" %c is the correct answer. Congratulations!!! You have won Rs.%s", arr2[num], arr1[i]);
            	 }
            	else
            	if(i >= 7 && i <= 11)
            	{
                	printf(" %c is the correct answer. Congratulations!!! You have won Rs.%s", arr2[num], arr1[i]);
                	printf("%s, you are playing very well. You are only %d questions away from winning Rs.5 crores.", name, 12-i);
            	}
            	else
            	{
                	printf(" %c is the correct answer. Congratulations!!! You have won Rs.%s", arr2[num], arr1[i]);
                	printf("\nYou have played fantastic and now you can fulfill your dreams with this huge amount of Rs.%s", arr1[i]);
            	}
            	pm = arr1[i];
         }
         else
         if(ans == 'L' || ans == 'l')
         {
                lifeline();  //calls the lifeline function
         }
         else
         if(ans == 'Q' || ans == 'q') //if the contestant quits
         {
            	quit(pm);
         }
         else
         if(ans != 'A' || ans != 'B' || ans != 'C' || ans != 'D' || ans != 'l' || ans != 'L' || ans != 'Q' || ans != 'q') //if the answer is wrong
         {
            	printf("\nSorry!!! This is the wrong answer. The correct answer is %c", arr2[num]);
            	lost(pm);
         }
         else
         {
            	printf("\nThis is an invalid answer. Enter the answer again");
            	answe();
         }
}
	
void generate()//to generate random questions
{
	while(1)
	{	
		srand(time(NULL));
        	int n = rand() % 23;//generates random numbers
        	num = search(n); //calls the search function
      		if(num == 1) //if the question is not printed
      	        {
                	searc[i] = n;  //stores the question number in an array
                	num = n;
			break;        
		}
	}
}

int search(int num1)//to generate random questions
{
        ctr = 0;
        x = 13;//length of the array search
        for(k = 0; k < i; k++)
        {
        	if(searc[k] == num1) //if number is found
            	{
                	ctr++;
            	}
        }
        if(ctr > 0)
        {
                return 0; //returns the value '0'
        }
        else
        {
                return 1; //returns the value '1'
        }
}

void quit(char *pwon)//if the contestant quits the game
{
        printf("\n");
        printf("%s has quit the game.\n", name);
        if(i == 0)
        {
        	printf("%s, you have not won anything from here.\n", name);
        }
        else
        {
                printf("%s, you have won Rs. %s", name, pwon);
                printf("\nYou had played very well.");
        }
        printf("\nThank you %s, for playing Kaun Banega Crorepati.", name);
        printf("\nGood Bye and have a nice day.");
        printf("\nEnd of GAME.");
          	
        printf("Press '1' to play again...."); //if the contestant wants to play again
        printf("Press any other key to exit....");
        scanf("%d", &again);
        if(again == 1)
        {
        	main(); //if the contestant plays again
        }
        else
        {
        	exit(10); //if the contestant does not want to play again   
        }
}

void lost(char *pwon)//if the contestant has given the wrong answer and lost
{
        printf("\n");
        printf("%s has lost the game.\n", name);
        if(i == 0 || i == 1)
        {
        	printf("\nSorry but you will take nothing from here.");
        }
        else
        if(i >= 2 && i <= 7)
        {
        	printf("\nSorry, but you will take away only Rs.10000 from here");
        }
        else
        {
        	printf("\nYou have played very well and you will take away Rs.3,20,000 from here");
        }
        printf("\nThank you %s, for playing Kaun Banega Crorepati.", name);
       	printf("\nGood Bye and have a nice day.");
       	printf("\nEnd of GAME.");
        	      
       	printf("Press '1' to play again...."); //if the contestant wants to play again
       	printf("Press any other key to exit....");
       	scanf("%d", &again);
       	if(again == 1)
       	{
       		main(); //if the contestant plays again
        }
        else
        {    
                exit(1000); //if the contestant does not want to play again
       	}
}   
