import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;

public class Rezolvariprobleme {

    public Rezolvariprobleme() {}

    public double pb2(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {

        int p1p, p1q, p2p, p2q;
        p1p = p1.getKey(); p1q = p1.getValue(); p2p = p2.getKey(); p2q = p2.getValue();
        int n1 = p1p - p1q, n2 = p2p - p2q;
        double rez = Math.sqrt(n1 * n1 + n2 * n2);
        return rez;
    }

    public Collection<String> pb4v2(String str) {
        String[] strs = str.split(" ");
        HashMap<String,String> hm = new HashMap<>();
        HashMap<String,String> hm2 = new HashMap<>();
        String[] list = new String[100];
        for(String cuv : strs) {
            if(hm.get(cuv) != null) {
                hm.remove(cuv);
                hm2.put(cuv,cuv);
            }
            else hm.put(cuv,cuv);
        }
        Collection<String> ls = hm.values();
        return ls;
    }

    public String pb1(String str) {
        String[] strs = str.split(" ");
        String rez = strs[0];
        for(String cuv : strs) {
            if(rez.compareTo(cuv) < 0)
                rez = cuv;
        }
        return rez;
    }

    String fpb8(int n) {
        String s = "";
        while(n != 0) {
            s = (n%2) + s;
            n /= 2;
        }
        return s;
    }

    public Collection<String> pb8(int n) {
        Collection<String> list = new ArrayList<>();
        list.add("0");
        for(int i = 0; i <= n; ++i) {
            String val = fpb8(i);
            if(val != "")
            list.add(val);
        }
        return list;
    }

    public Integer pb5(Integer[] s) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int i : s) {
            if(hm.get(i) == null)
                hm.put(i,i);
            else return i;
        }
        return -1;
    }

}
