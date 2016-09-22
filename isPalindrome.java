
import java.util.*;
import java.lang.*;
import java.io.*;


class Ideone
{
	public static boolean isPalindrome( String s, int first, int last ) {
		if (first == last ){
			return true;
		} 
		if (s.charAt(first) != s.charAt(last)) { 
			return false; 
		} else { 
			isPalindrome(s, first+1, last-1); 
		}
		
		return true;
	}

	public static void main(String[] args) {	
		String word = "racecar";
		int end = word.length()-1;
		if(isPalindrome(word, 0, end) == true) {
			System.out.println("is a palindrome.");
		} else {
			System.out.println("is not a palindrome");
		}

		String word2 = "race";
                end = word2.length()-1;
                if(isPalindrome(word2, 0, end) == true) {
                        System.out.println("is a palindrome.");
                } else {
                        System.out.println("is not a palindrome");
                }
		
		String word3 = "carrac";
                end = word3.length()-1;
                if(isPalindrome(word3, 0, end) == true) {
                        System.out.println("is a palindrome.");
                } else {
                        System.out.println("is not a palindrome");
                }

		String word5 = "abcdefghijklmnopponmlkjihgfedcba";
                end = word5.length()-1;
                if(isPalindrome(word5, 0, end) == true) {
                        System.out.println("is a palindrome.");
                } else {
                        System.out.println("is not a palindrome");
                }
	}
}
