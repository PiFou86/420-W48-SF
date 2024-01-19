using Microsoft.AspNetCore.Mvc;

namespace M13_CoeurReacteurCSharp.Controllers;

[ApiController]
[Route("/coeur-reacteur")]
public class CoeurReacteurController : ControllerBase
{
    private const string EtatRepos = "repos";
    private const string EtatActif = "actif";

    private static object _object = new object();
    private static EtatReacteur _etatReacteur = new EtatReacteur()
    {
        Etat = "repos"
    };

    [HttpGet()]
    public ActionResult<EtatReacteur> Get()
    {
        return Ok(_etatReacteur);
    }

    [HttpPut()]
    public ActionResult<EtatReacteur> Put([FromBody] EtatReacteur p_etatReacteur)
    {
        if (p_etatReacteur.Etat != EtatRepos && p_etatReacteur.Etat != EtatActif)
        {
            return BadRequest();
        }

        lock (_object)
        {
            _etatReacteur.Etat = p_etatReacteur.Etat;
        }
        
        return Ok(_etatReacteur);
    }
}
