package Repository;

import Domain.User;
import org.junit.Test;

import static org.junit.Assert.*;

public class UserRepoTest {

    @Test
    public void save() {

        UserRepo<String> ur = new UserRepo<>();

        Integer firstRowCount = ur.getLg();

        User<String> u1 = new User<>("Razvan2","Romete2");
        User<String> u3 = new User<>("Iulius2","Romete2");
        User<String> u2 = new User<>("Dragos2","Romete2");

        ur.save(u1);
        ur.save(u2);
        ur.save(u3);

        Integer secondRowCount = ur.getLg();

        assertEquals(( secondRowCount - firstRowCount ), 3);

        ur.delete(ur.getIdByUaP(u1));
        ur.delete(ur.getIdByUaP(u2));
        ur.delete(ur.getIdByUaP(u3));

    }

    @Test
    public void get() {

        UserRepo<String> ur = new UserRepo<>();

        User<String> u1 = new User<>("Razvan2","Romete2");

        ur.save(u1);

        User<String> u2 = ur.get(ur.getIdByUaP(u1));

        ur.delete(ur.getIdByUaP(u1));

        assertEquals((u2).getName(), "Razvan2");

    }

    @Test
    public void delete() {

        UserRepo<String> ur = new UserRepo<>();

        Integer firstRowCount = ur.getLg();

        User<String> u1 = new User<>("Razvan2","Romete2");

        ur.save(u1);

        ur.delete(ur.getIdByUaP(u1));

        assertEquals(ur.getLg(), firstRowCount);

    }

    @Test
    public void update() {

        UserRepo<String> ur = new UserRepo<>();

        User<String> u1 = new User<>("Razvan2","Romete2");

        ur.save(u1);

        User<String> u2 = new User<>(ur.getIdByUaP(u1),"Razvan3","Romete3");

        ur.update(u2);

        User<String> u3 = ur.get(ur.getIdByUaP(u2));

        assertEquals(u3.getName(),"Razvan3");
        assertEquals(u3.getPassword(),"Romete3");

        ur.delete(u3.getId());

        //assertTrue(false);

    }
}