using Almostengr.AlmostengrWebsite.WeatherObservation;

namespace Almostengr.AlmostengrWebsite;

class Program
{
    static async Task<int> Main()
    {
        var observationService = new NwsDailyObservationService();
        return await observationService.GetWeatherDataAsync();
    }
}
