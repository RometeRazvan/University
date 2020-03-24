package Domain.Validator;

import Domain.Donatie;
import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class ValidatorTest {

    @Test
    public void validate() throws ValidationException {
        Validator validator = new Validator();

        Donatie d1 = new Donatie("Razvan Romete", "asdasdasd", "0740538816", 100);
        try { validator.validate(d1); assertTrue(true); } catch (ValidationException e) { assertTrue(false);}

        Donatie d2 = new Donatie("Razvan", "asdasdasd", "0740538816", -100);
        try { validator.validate(d2); assertTrue(false); } catch (ValidationException e) { assertTrue(true);}

        Donatie d3 = new Donatie("Razvan", "asdasdasd", "0740538asd", 100);
        try { validator.validate(d3); assertTrue(false); } catch (ValidationException e) { assertTrue(true);}

        Donatie d4 = new Donatie("Razvan2", "asdasdasd", "0740538816", 100);
        try { validator.validate(d4); assertTrue(false); } catch (ValidationException e) { assertTrue(true);}

        Donatie d5 = new Donatie("Razvan RomeTe", "asdasdasd", "0740538816", 100);
        try { validator.validate(d5); assertTrue(false); } catch (ValidationException e) { assertTrue(true);}

    }
}