package Domain.Validator;

import Domain.Entity;

public interface IValidator<E extends Entity> {

    void validate(E entity) throws ValidationException;

}
