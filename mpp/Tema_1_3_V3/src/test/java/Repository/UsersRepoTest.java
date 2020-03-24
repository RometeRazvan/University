package Repository;

import Domain.User;
import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;

import java.sql.SQLException;

import static org.junit.Assert.*;

public class UsersRepoTest {
    private static UsersRepo ur;
    private static User u1, u2, u3;

    @BeforeClass
    public static void initiate() throws SQLException {
        ur = new UsersRepo();
        ur.getConnection().setAutoCommit(false);
        u1 = ur.save(new User("razvan2", "romete2"));
        u2 = ur.save(new User("radu2", "dragos2"));
        u3 = ur.save(new User("iulius2", "satmari2"));
    }

    @AfterClass
    public static void finalTest() throws SQLException {
        ur.getConnection().rollback();
        ur.getConnection().close();
    }

    @Test
    public void findByName() {
        assertTrue(u1.equals(ur.findByName("razvan2")));
        assertTrue(u2.equals(ur.findByName("radu2")));
        assertTrue(u3.equals(ur.findByName("iulius2")));
    }

    @Test
    public void findOne() {
        assertEquals(ur.findOne(u1.getId()), u1);
        assertEquals(ur.findOne(u2.getId()), u2);
        assertEquals(ur.findOne(u3.getId()), u3);
    }

}