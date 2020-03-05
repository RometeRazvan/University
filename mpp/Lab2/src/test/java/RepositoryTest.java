import org.junit.Test;

import static org.junit.Assert.*;

public class RepositoryTest {

    Repository<String> repo = new Repository<>();

    public void testAll() {
        findOne();
    }

    @Test
    public void findOne() {

        assertEquals(repo.findOne("1"),"Razvan");
        System.out.println("Finalizare test findOne !");

    }

    @Test
    public void save() {
        assertEquals();
    }

    @Test
    public void delete() {
    }
}