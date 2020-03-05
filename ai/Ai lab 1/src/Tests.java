import javafx.util.Pair;
import org.junit.Test;

import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;

import static org.junit.Assert.*;

public class Tests {

    public void testAll() {
        testPb1();
        testPb2();
        testPb4();
        testPb5();
        testPb8();
    }

    @Test
    public void testPb4() {
        Collection<String> ls = new ArrayList<>();
        ls.add("si"); ls.add("mere");
        assertTrue(new HashSet<>(ls).equals(new HashSet<>(new Rezolvariprobleme().pb4v2("ana ana mere si pere pere"))));


        Collection<String> ls2 = new ArrayList<>();
        ls2.add("1"); ls2.add("2");
        assertTrue(new HashSet<>(ls2).equals(new HashSet<>(new Rezolvariprobleme().pb4v2("1 3 3 4 4 2"))));
        System.out.println("Finalizare test 4");
    }

    @Test
    public void testPb1() {
        assertEquals(new Rezolvariprobleme().pb1("Ana are mere si pere"),"si");
        assertEquals(new Rezolvariprobleme().pb1("Ana are mere si xi pere"),"xi");
        System.out.println("Finalizare test 1");
    }

    @Test
    public void testPb2() {
        Pair<Integer,Integer> p1 = new Pair<>(1,5);
        Pair<Integer,Integer> p2 = new Pair<>(4,1);
        assertEquals(5.0,new Rezolvariprobleme().pb2(p1,p2),0.1);
        System.out.println("Finalizare test 2");
    }

    @Test
    public void testPb8() {
        Collection<String> list = new ArrayList<>();
        list.add("1"); list.add("10"); list.add("11"); list.add("100"); list.add("0");
        //System.out.println(1);
        /*for(String s : new Rezolvariprobleme().pb8(4))
            System.out.println(s);
        for(String s : list)
            System.out.println(s);*/
        assertTrue(new HashSet<>(list).equals(new HashSet<>(new Rezolvariprobleme().pb8(4))));
        //Collection<String> list2 =  new Rezolvariprobleme().pb8(4);
        //assertArrayEquals(list.toArray(),list2.toArray());
        System.out.println("Finalizare test 8");
    }

    @Test
    public void testPb5() {
        Integer[] s = {1, 2, 3 , 4, 5 , 2};
        assertEquals((Integer) 2,new Rezolvariprobleme().pb5(s));
        System.out.println("Finalizare test 5");
     }

}
