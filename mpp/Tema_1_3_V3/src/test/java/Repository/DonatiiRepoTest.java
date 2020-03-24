package Repository;

import Domain.Donatie;
import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;

import java.sql.SQLException;

import static org.junit.Assert.*;

public class DonatiiRepoTest {
    public static DonatiiRepo dr;
    public static Donatie d1, d2, d3;

    @BeforeClass
    public static void Initializare() throws SQLException {
        dr = new DonatiiRepo();
        dr.getConneection().setAutoCommit(false);
        d1 = dr.save(new Donatie("razvan2", "adr2", "0740538816", 1000));
        d2 = dr.save(new Donatie("razvan3", "adr3", "0560538816", 1000));
        d3 = dr.save(new Donatie("razvan4", "adr4", "0760538816", 1000));
    }

    @AfterClass
    public static void finalTest() throws SQLException {
        dr.getConneection().rollback();
        dr.getConneection().close();
    }

    @Test
    public void findByNameAddressPhone() {
        assertTrue(d1.equals(dr.findByNameAddressPhone("razvan2", "adr2", "0740538816")));
        assertTrue(d2.equals(dr.findByNameAddressPhone("razvan3", "adr3", "0560538816")));
        assertTrue(d3.equals(dr.findByNameAddressPhone("razvan4", "adr4", "0760538816")));
    }

    @Test
    public void findByName() {
        assertTrue(d1.equals(dr.findByName("razvan2")));
        assertTrue(d2.equals(dr.findByName("razvan3")));
        assertTrue(d3.equals(dr.findByName("razvan4")));
    }

    @Test
    public void findOne() {
        assertTrue(d1.equals(dr.findOne(d1.getId())));
        assertTrue(d2.equals(dr.findOne(d2.getId())));
        assertTrue(d3.equals(dr.findOne(d3.getId())));
    }
}