/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

        double[] pair;
        ArrayList data = new ArrayList<>();

        double j, k;

        String lines;
        String[] strs;

        do {
            lines = br.readLine();

            strs = lines.trim().split(" ");

            j = Integer.parseInt(strs[0]);
            k = Integer.parseInt(strs[1]);

            if ((j >= 0 && j <= 10000) && (k >= 0 && j <= 100)) {
                pair = new double[]{j, k};

                data.add(pair);
            } else {
                System.out.println("¡Input not valid!");
            }

        } while (j != 0 || k != 0);

        System.out.println();

        int fil = data.size() - 1;

        double[][] aDepth = new double[fil][3];

        Iterator itr = data.iterator();

        int i = 0;
        while (i < fil) {
            pair = (double[]) itr.next();
            aDepth[i][0] = pair[0] / 2;
            aDepth[i][1] = pair[1] / 100;

            aDepth[i][2] = (Math.pow(aDepth[i][0], 2) - Math.pow(aDepth[i][1], 2)) / (2 * aDepth[i][1]);
            aDepth[i][2] = (double) Math.round(aDepth[i][2] * 10) / 10;

            System.out.println(aDepth[i][2]);
            i++;
        }
    }

}
