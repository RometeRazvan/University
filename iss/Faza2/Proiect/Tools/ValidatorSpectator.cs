using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms.VisualStyles;
using Faza2.Domain;

namespace Faza2.Tools
{
    class ValidatorSpectator
    {
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public ValidatorSpectator() { }

        public bool validate(Spectator spectator)
        {
            string error = "";

            try
            {
                string litere = "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ ";

                foreach (char chr in spectator.nume)
                {
                    if (!litere.Contains(chr))
                    {
                        error += "Nume invalid !!!\n";
                        break;
                    }
                }

                string numere = "1234567890";

                if (spectator.telefon.Length != 10)
                    error += "Telefon Invalid !!!\n";
                else
                {
                    foreach (char chr in spectator.telefon)
                    {
                        if (!numere.Contains(chr))
                        {
                            error += "Telefon invalid !!!\n";
                            break;
                        }
                    }
                }

                bool prea = false;
                bool bap = false;
                bool postp = false;

                if(numere.Contains(spectator.email.ElementAt(0)))
                {
                    error += "Email invalid !!!\n";
                }
                else
                {
                    foreach (char chr in spectator.email)
                    {
                        if (prea == false && litere.Contains(chr))
                            prea = true;

                        if (chr == '@' && prea == false)
                        {
                            error += "Email invalid !!!\n";
                            break;
                        }

                        if (prea == true && bap == false && litere.Contains(chr))
                            bap = true;

                        if (chr == '.' && bap == false)
                        {
                            error += "Email invalid !!!\n";
                            break;
                        }

                        if (bap == true && litere.Contains(chr))
                            postp = true;
                    }

                    if (postp == false || prea == false || bap == false)
                        error += "Email invalid !!!\n";
                }
            }
            catch(Exception ex)
            {
                logger.Error(ex.Message);
                return false;
            }

            if (error != "")
                throw new Exception(error);

            return true;
        }
    }
}
