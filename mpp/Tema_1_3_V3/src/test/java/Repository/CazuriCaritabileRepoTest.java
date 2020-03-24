package Repository;

import Domain.Caritate;
import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashSet;

import static org.junit.Assert.*;

public class CazuriCaritabileRepoTest {

    private static CazuriCaritabileRepo ccu;
    private static Caritate c1, c2, c3;

    @BeforeClass
    public static void initializare() throws SQLException {
        ccu = new CazuriCaritabileRepo();
        ccu.getConnection().setAutoCommit(false);
        c1 = ccu.save(new Caritate("Copii"));
        c2 = ccu.save(new Caritate("Incendii"));
        c3 = ccu.save(new Caritate("Dezastre Naturale"));
    }

    @AfterClass
    public static void FinalTest() throws SQLException {
        ccu.getConnection().rollback();
        ccu.getConnection().close();
    }

    @Test
    public void findByName() {
        assertTrue(c1.equals(ccu.findByName("Copii")));
        assertTrue(c2.equals(ccu.findByName("Incendii")));
        assertTrue(c3.equals(ccu.findByName("Dezastre Naturale")));
    }

    @Test
    public void findAll() {
        ArrayList<Caritate> it = (ArrayList<Caritate>) ccu.findAll();
        ArrayList<Caritate> al = new ArrayList<>(); al.add(c1); al.add(c2); al.add(c3);

        assertTrue(it.contains(c1));
        assertTrue(it.contains(c2));
        assertTrue(it.contains(c3));
    }

    @Test
    public void findOne() {
        assertTrue(c1.equals(ccu.findOne(c1.getId())));
        assertTrue(c2.equals(ccu.findOne(c2.getId())));
        assertTrue(c3.equals(ccu.findOne(c3.getId())));
    }
}