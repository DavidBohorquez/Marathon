
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Andre Sarmiento
 */
public class XGenerationalAdder {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;

        String[] aLine;

        do {
            line = br.readLine();

            aLine = line.trim().split(" ");

            /*for(int i = 0; i < aLine.length; i++) {
             System.out.println(aLine[i]);
             }*/
            int i = Integer.parseInt(aLine[aLine.length - 1]);

        } while (true);
    }

}
