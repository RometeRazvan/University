package Service;

import Domain.Caritate;
import Repository.CazuriCaritabileRepo;

public class ServiceCaritate implements IServiceCaritate<Caritate> {
    private CazuriCaritabileRepo ccr;

    public ServiceCaritate(CazuriCaritabileRepo ccr) {
        this.ccr = ccr;
    }

    public ServiceCaritate() {
        this.ccr = new CazuriCaritabileRepo();
    }

    @Override
    public Caritate findByName(String nume) {
        return ccr.findByName(nume);
    }

    @Override
    public Iterable<Caritate> findAll() {
        return ccr.findAll();
    }

    @Override
    public Caritate findOne(int id) {
        return ccr.findOne(id);
    }
}
