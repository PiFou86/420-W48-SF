using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Mvc;

namespace M13_CoeurReacteurCSharp.Controllers;

public class HomeController : Controller
{
    [EnableCors()]
    public IActionResult Index()
    {
        return View();
    }
}
