using Almostengr.AlmostengrWebsite.Domain.WeatherObservation;
using Almostengr.AlmostengrWebsite.Infrastructure;
using Almostengr.AlmostengrWebsite.Domain.Common.Interfaces;

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
