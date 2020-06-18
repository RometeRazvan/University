using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Faza2.Domain;
using Faza2.Observers;
using Faza2.Repository;
using Faza2.Tools;

namespace Faza2.Service
{
    public class ServiceTerminal : Observer
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        private RepositoryLoc repoLoc;
        private RepositorySpectator repoSpectator;
        private RepositoryRezervare repoRezervare;
        private RepositoryPiesa repoPiesa;

        private ValidatorSpectator validatorSpectator;

        private List<Observable> observables;

        public ServiceTerminal() {
            this.repoLoc = new RepositoryLoc();
            this.repoSpectator = new RepositorySpectator();
            this.repoRezervare = new RepositoryRezervare();
            this.repoPiesa = new RepositoryPiesa();
            this.observables = new List<Observable>();
            this.validatorSpectator = new ValidatorSpectator();
        }

        public void addObservable(Observable observable)
        {
            observables.Add(observable);
        }

        public void notifyObservables()
        {
            foreach(Observable observable in observables)
            {
                observable.getNotified();
            }
        }
        public List<Loc> findAllLoc()
        {
            try
            {
                return repoLoc.findAll();
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public void changeStateLoc(List<string> list)
        {
            try
            {
                repoLoc.changeState(list);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public void addSpectator(Spectator spectator)
        {
            validatorSpectator.validate(spectator);
            try
            {
                repoSpectator.add(spectator);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public void addRezervare(List<Rezervare> list)
        {
            try
            {
                repoRezervare.add(list);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public Loc findLocByPozitie(string pozitie)
        {
            try
            {
                return repoLoc.findByPozitie(pozitie);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public Piesa findPiesaByNume(string nume)
        {
            try
            {
                return repoPiesa.findByNume(nume);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public Spectator findSpectatorByData(string nume, string telefon, string email)
        {
            try
            {
                return repoSpectator.findByData(nume, telefon, email);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public List<Rezervare> findRezervareByIdSpectator(Guid id)
        {
            try
            {
                return repoRezervare.findByIdSpectator(id);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public void deleteSpectatorNumeSpectator(string nume, string telefon, string email)
        {
            try
            {
                repoSpectator.deleteByData(nume, telefon, email);
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public void deleteRezervareBySpectator(Spectator spectator)
        {
            try
            {
                repoRezervare.deleteBySpectator(spectator);
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public Loc findLocById(Guid id)
        {
            try
            {
                return repoLoc.findById(id);
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }

        public void deleteAllSpectator()
        {
            try
            {
                repoSpectator.deleteAll();
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public void deleteAllRezervare()
        {
            try
            {
                repoRezervare.deleteAll();
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }
        }

        public List<Spectator> findAllSpectator()
        {
            try
            {
                return repoSpectator.findAll();
            }
            catch (Exception ex)
            {
                logger.Error(ex.Message);
            }

            return null;
        }
    }
}
