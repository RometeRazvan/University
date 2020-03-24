package Domain.Validator;

import Domain.Donatie;
import Domain.Entity;
import Domain.User;

public class Validator implements IValidator<Entity> {
    @Override
    public void validate(Entity entity) throws ValidationException {
        if(entity instanceof Donatie) new ValidateDonatie().validate((Donatie) entity);
    }
}
