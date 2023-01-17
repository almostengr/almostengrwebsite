namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation;

public interface INwsDailyObservationService
{
    Task<int> GetWeatherDataAsync();
}