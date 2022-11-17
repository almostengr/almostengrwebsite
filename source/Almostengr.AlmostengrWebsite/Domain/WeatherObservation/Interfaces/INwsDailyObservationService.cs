namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Interfaces;

public interface INwsDailyObservationService
{
    Task<int> GetWeatherDataAsync();
}