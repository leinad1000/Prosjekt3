#include "tenbody.h"
#include "vec3.h"
#include "system.h"
#include <cmath>


void TenBody::setupParticles(System &system) { 
    double pi = M_PI;
    double dager = 365.2522;
    // Get initial conditions from NASA's public service. Data below as of october 12th 2017.
    Particle* Sun = new Particle(vec3(2.249742341967526E-03,5.702259020296952E-03,-1.308868418264601E-04), dager * vec3(-5.176331796449613E-06,5.522815922934838E-06,1.208552996089031E-07), (1.99/5.974)*(1e6));
    Particle* Mercury = new Particle(vec3(-3.787765979540608E-01,-1.822820556608564E-01,1.946364572516068E-02), dager * vec3(6.639513358754547E-03,-2.399984280022258E-02,-2.571010368861300E-03), 0.0549882826);
    Particle* Venus = new Particle(vec3(-5.895447258261073E-01,4.113399941375999E-01,3.958359273166973E-02), dager * vec3(-1.152142811351218E-02,-1.677859771759771E-02,4.344523056718858E-04), 0.8147505859);
    Particle* EarthMoon = new Particle(vec3(9.480895986913122E-01,3.243098104795900E-01,-1.483258059003856E-04), dager * vec3(-5.777303447041140E-03,1.624578585985101E-02,-5.327530311212426E-07), 1.0122994193);
    Particle* Mars = new Particle(vec3(-1.540775834917753E+00,6.318374030745555E-01,5.085869013425003E-02), dager * vec3(-4.742251167677201E-03,-1.176588347335337E-02,-1.302988318954905E-04), 0.1074142953);
    Particle* Ceres = new Particle(vec3(-6.445305683469671E-01,2.537473592854052E+00,1.988126611018326E-01), dager * vec3(-1.022525969113024E-02,-3.354300441680958E-03,1.778470896838727E-03), 0.0009393);
    Particle* Jupiter = new Particle(vec3(-4.604440597510837,-2.891007523243876,1.149787438139007E-01), dager * vec3(3.925073055856761E-03,-6.032031115361013E-03,-6.270510562667993E-05), (1.898/5.974)*(1e3));
    Particle* Saturn = new Particle(vec3(-3.790768464407142E-01,-1.004811933118735E+01,1.897936890208218E-01), dager * vec3(5.268080367079689E-03,-2.277337042199548E-04,-2.059484097729237E-04), 95.12889186);
    Particle* Uranus = new Particle(vec3(1.786847909037686E+01,8.793101880397845E+00,-1.988312286911673E-01), dager * vec3(-1.765372076056564E-03,3.345607679959963E-03,3.534922695016412E-05), 14.53130231);
    Particle* Neptun = new Particle(vec3(2.860931715814051E+01,-8.836432401622716E+00,-4.773613959400135E-01), dager * vec3(9.053217800158139E-04,3.017556437109072E-03,-8.326738981989289E-05), 17.14094409);
    Particle* PlutoCharon = new Particle(vec3(1.053181155457697E+01,-3.171423872037187E+01,3.471945855290703E-01), dager * vec3(3.045967890890119E-03,3.332278774698788E-04,-9.167352948563432E-04), 0.0024566455);

    
    system.addParticle(Sun);
    system.addParticle(Mercury);
    system.addParticle(Venus);
    system.addParticle(EarthMoon);
    system.addParticle(Mars);
    system.addParticle(Ceres);
    system.addParticle(Jupiter);
    system.addParticle(Saturn);
    system.addParticle(Uranus);
    system.addParticle(Neptun);
    system.addParticle(PlutoCharon);

    
}

std::string TenBody::getName() {
    return "Ten-body";
}
