package Domain.Validator;

import Domain.Donatie;

public class ValidateDonatie implements IValidator<Donatie> {

    private boolean validateName(String nume) {
        String str = "abcdefghijklmnopqrstuvxyz";
        String bigString = "ABCDEFGHIJKLNOPQRSTUVXYZ";
        String smallAndBig= "ABCDEFGHIJKLNOPQRSTUVXYZabcdefghijklmnopqrstuvxyz";

        if(smallAndBig.indexOf(nume.charAt(0)) == -1) return false;

        for(int i = 1; i < nume.length(); ++i) {
            if(bigString.indexOf(nume.charAt(i)) != -1
                    && nume.charAt(i - 1) != ' ') return false;
            if(nume.charAt(i) != ' '
                    && smallAndBig.indexOf(nume.charAt(i)) == -1) return false;
            if(bigString.indexOf(nume.charAt(i)) != -1 &&
                str.indexOf(nume.charAt(i - 1)) != -1) return false;
        }

        return true;
    }

    private boolean validateNrTel(String nrTel) {
        String nr = "1234567890";

        if(nrTel.charAt(0) != '0' && nrTel.charAt(1) != 7) return false;

        if(nr.length() != 10) return false;

        for(int i = 2; i < 10; ++i){
            if(nr.indexOf(nrTel.charAt(i)) == -1)
                return false;
        }

        return true;
    }

    private boolean validateSuma(int suma) {
        if(suma < 0) return false;

        return true;
    }

    @Override
    public void validate(Donatie entity) throws ValidationException {
        if(validateName(entity.getNume()) == false)
            throw new ValidationException("Nume invalid");

        if(validateNrTel(entity.getNrTel()) == false)
            throw new ValidationException("Numar de telefon invalid");

        if(validateSuma(entity.getSuma()) == false)
            throw new ValidationException("Suma invalida");
    }
}
