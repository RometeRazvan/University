package Repository;

import Domain.Donatie;
import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;

import java.sql.SQLException;
import java.util.ArrayList;

import static org.junit.Assert.*;

public class DonatiiRepoTest {
    public static DonatiiRepo dr;
    public static Donatie d1, d2, d3;

    @BeforeClass
    public static void Initializare() throws SQLException {
        dr = new DonatiiRepo();
        dr.getConneection().setAutoCommit(false);
        d1 = dr.save(new Donatie("razvan 2", "adr2", "0740538816", 1000));
        d2 = dr.save(new Donatie("razvan 3", "adr3", "0560538816", 1000));
        d3 = dr.save(new Donatie("razvan 4", "adr4", "0760538816", 1000));
    }

    @AfterClass
    public static void finalTest() throws SQLException {
        dr.getConneection().rollback();
        dr.getConneection().close();
    }

    @Test
    public void findByNameAddressPhone() {
        assertTrue(d1.equals(dr.findByNameAddressPhone("razvan 2", "adr2", "0740538816")));
        assertTrue(d2.equals(dr.findByNameAddressPhone("razvan 3", "adr3", "0560538816")));
        assertTrue(d3.equals(dr.findByNameAddressPhone("razvan 4", "adr4", "0760538816")));
    }

    @Test
    public void findByName() {
        assertTrue(d1.equals(dr.findByName("razvan 2")));
        assertTrue(d2.equals(dr.findByName("razvan 3")));
        assertTrue(d3.equals(dr.findByName("razvan 4")));
    }

    @Test
    public void findOne() {
        assertTrue(d1.equals(dr.findOne(d1.getId())));
        assertTrue(d2.equals(dr.findOne(d2.getId())));
        assertTrue(d3.equals(dr.findOne(d3.getId())));
    }

    @Test
    public void searchByPartialName() {
        ArrayList<Donatie> al = (ArrayList<Donatie>) dr.searchByPartialName("razvan");
        al.contains(d1);
        al.contains(d2);
        al.contains(d3);
    }
}