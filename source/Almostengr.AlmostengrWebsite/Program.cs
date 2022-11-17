using Almostengr.AlmostengrWebsite.Domain.WeatherObservation;
using Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Interfaces;
using Almostengr.AlmostengrWebsite.Infrastructure;
using Almostengr.AlmostengrWebsite.Infrastructure.Interfaces;

namespace Almostengr.AlmostengrWebsite;

class Program
{
    static async Task<int> Main()
    {
        INwsObservationHttpClient httpClient = new NwsObservationHttpClient();
        INwsDailyObservationService observationService = new NwsDailyObservationService(httpClient);
        return await observationService.GetWeatherDataAsync();
    }
}
