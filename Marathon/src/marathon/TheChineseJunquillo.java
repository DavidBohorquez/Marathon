/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package marathon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

/**
 *
 * @author Andre Sarmiento
 */
public class TheChineseJunquillo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] pair;
        ArrayList data = new ArrayList<>();

        int j, k;

        String lines;
        String[] strs;

        do {
            lines = br.readLine();

            strs = lines.trim().split("\\s+");

            j = Integer.parseInt(strs[0]);
            k = Integer.parseInt(strs[1]);

            if ((j >= 0 && j <= 10000) && (k >= 0 && j <= 100)) {
                pair = new int[]{j, k};

                data.add(pair);
            } else {
                System.out.println("¡Input not valid!");
            }

        } while (j != 0 || k != 0);

        System.out.println("Output");

        Iterator itr = data.iterator();

        while (itr.hasNext()) {
            pair = (int[]) itr.next();
            System.out.println(pair[0] + pair[1]);
        }
    }

}
